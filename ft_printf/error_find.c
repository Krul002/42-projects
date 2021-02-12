/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:53:41 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/14 15:53:43 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_args_error(char *str, int *i, int count, va_list ap)
{
	int						par[11];

	*i = set_param(str, *i, ap, par);
	if (par[9] == 0)
		return (-1);
	return (count);
}

int		print_error(va_list ap, const char *str, int count)
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
			count += i - j;
			count = print_args_error(s, &i, count, ap);
			j = i;
		}
		else
			i++;
	}
	if (count >= 0)
		count += i - j;
	return (count);
}
