/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:46:49 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:46:51 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_va_arg1(char **s, va_list ap, int *par)
{
	int		i;
	char	*g;

	i = 0;
	*s = 0;
	if (par[9] == 's')
	{
		*s = (char *)va_arg(ap, char *);
		g = *s;
		if (g != 0)
		{
			while (g[i] != 0)
				i++;
			par[10] = i;
		}
		else
			par[10] = 6;
	}
}

void	ft_va_arg2(long long int *d, va_list ap, int *par)
{
	long long int i;

	i = 0;
	if (par[9] == '%')
	{
		i = '%';
		par[10] = 1;
	}
	else if (par[9] == 'd' || par[9] == 'i')
	{
		i = (par[8] == 0) ? (int)va_arg(ap, int) : i;
		i = (par[8] == 1) ? (short int)va_arg(ap, int) : i;
		i = (par[8] == 2) ? (char)va_arg(ap, int) : i;
		i = (par[8] == 3) ? (long int)va_arg(ap, long) : i;
		i = (par[8] == 4) ? (long long int)va_arg(ap, long long) : i;
		par[10] = ft_nbrlen(i, 0, 10);
	}
	*d = i;
}

void	ft_char(long long unsigned int *u, va_list ap, int *par)
{
	if (par[8] > 0)
	{
		*u = (unsigned int)va_arg(ap, int);
		par[10] = 1;
		if (*u >> 24)
			par[10] = 4;
		else if (*u >> 16)
			par[10] = 3;
		else if (*u >> 8)
			par[10] = 2;
	}
	else
	{
		*u = (unsigned char)va_arg(ap, int);
		par[10] = 1;
	}
}

void	ft_va_arg3(long long unsigned int *u, va_list ap, int *par)
{
	long long unsigned int i;

	i = 0;
	if (par[9] == 'c')
		ft_char(&i, ap, par);
	else if (par[9] == 'p')
	{
		i = (long unsigned int)va_arg(ap, long);
		par[10] = ft_nbrlen(0, i, 16);
	}
	else if (par[9] == 'u' || par[9] == 'x' || par[9] == 'X')
	{
		i = (par[8] == 0) ? (unsigned int)va_arg(ap, int) : i;
		i = (par[8] == 1) ? (short unsigned int)va_arg(ap, int) : i;
		i = (par[8] == 2) ? (unsigned char)va_arg(ap, int) : i;
		i = (par[8] == 3) ? (long unsigned int)va_arg(ap, long) : i;
		i = (par[8] == 4) ? (long long unsigned int)va_arg(ap, long long) : i;
		par[10] = ft_nbrlen(0, i, 16);
		if (par[9] == 'u')
			par[10] = ft_nbrlen(0, i, 10);
	}
	*u = i;
}

int		ft_indent(int width, int *minus)
{
	char	*s;
	int		i;

	*minus *= -1;
	if (*minus < 0)
		return (0);
	i = 0;
	if ((s = (char *)malloc(width + 1)) != 0)
	{
		while (i < width)
			s[i++] = ' ';
		write(1, s, width);
		free(s);
		return (width);
	}
	while (i++ < width)
		write(1, " ", 1);
	return (width);
}
