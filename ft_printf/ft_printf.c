/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:46:26 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:46:28 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
***par[0] - minus
***par[1] - null
***par[2] - plus
***par[3] - space
***par[4] - resh
***par[5] - width
***par[6] - acc
***par[7] - acc real
***par[8] - mod
***par[9] - arg
***par[10] - len
*/

int		set_param(char *s, int i, va_list ap, int *par)
{
	i += 1;
	ft_zero_par(par);
	i = flags(s, i, par);
	i = width(s, i, par, ap);
	if (s[i] == '.' && i++)
		i = accuracy(s, i, par, ap);
	i = mod(s, i, par);
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'd' || s[i] == 'i')
		par[9] = s[i];
	else if (s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
		par[9] = s[i];
	else if (s[i] == '%')
		par[9] = s[i];
	return (i + 1);
}

int		print_args(char *str, int *i, int count, va_list ap)
{
	int						j;
	int						par[11];
	char					*s;
	long long int			d;
	unsigned long long int	u;

	j = set_param(str, *i, ap, par);
	ft_va_arg1(&s, ap, par);
	ft_va_arg2(&d, ap, par);
	ft_va_arg3(&u, ap, par);
	ft_off_par(par, u, d);
	count += ft_indent(par[5], &par[0]);
	count += ft_accuracy(par[6], par, &d);
	count += print_argument1(s, d, par);
	count += print_argument2(u, par);
	count += ft_indent(par[5], &par[0]);
	*i = j;
	return (count);
}

int		print(va_list ap, const char *str, int count)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)str;
	while (s[i] != '\0' && count >= 0)
	{
		if (s[i] == '%')
		{
			count += write(1, &s[j], i - j);
			count = print_args(s, &i, count, ap);
			j = i;
		}
		else
			i++;
	}
	if (count >= 0)
		count += write(1, &s[j], i - j);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	va_start(ap, format);
	count = 0;
	count = print_error(ap, format, count);
	va_end(ap);
	if (count < 0)
		return (-1);
	va_start(ap, format);
	count = 0;
	count = print(ap, format, count);
	va_end(ap);
	return (count);
}
