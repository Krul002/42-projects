/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:46:49 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:46:51 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_symbol(long long int *d, int arg, int *par)
{
	if (*d < 0)
	{
		*d *= -1;
		return (write(1, "-", 1));
	}
	if (par[2] > 0)
		return (write(1, "+", 1));
	if (par[3] > 0)
		return (write(1, " ", 1));
	if ((par[4] > 0 && arg == 'x') || arg == 'p')
		return (write(1, "0x", 2));
	if ((par[4] > 0 && arg == 'X'))
		return (write(1, "0X", 2));
	return (0);
}

int		ft_accuracy(int acc, int *par, long long int *d)
{
	char	*s;
	int		i;
	int		n;

	n = ft_symbol(d, par[9], par);
	i = 0;
	if ((s = (char *)malloc(acc + 1)) != 0)
	{
		while (i < acc)
			s[i++] = '0';
		write(1, s, acc);
		free(s);
		return (acc + n);
	}
	while (i++ < acc)
		write(1, "0", 1);
	return (acc + n);
}

int		print_argument1(char *s, long long int d, int *par)
{
	if (par[9] == '%')
		write(1, &d, par[10]);
	else if (par[9] == 's')
	{
		if (s != 0)
			write(1, s, par[10]);
		else
			write(1, "(null)", par[10]);
	}
	else if (par[9] == 'd' || par[9] == 'i')
		print_nbr(d, 0, 'i', par[10]);
	if (par[9] == 's' || par[9] == 'd' || par[9] == 'i' || par[9] == '%')
		return (par[10]);
	return (0);
}

void	print_long_char(long long unsigned int u, int *par, char *s)
{
	if (u >> 24)
	{
		s[3] = u & 255;
		s[2] = u >> 8 & 255;
		s[1] = u >> 16 & 255;
		s[0] = u >> 24 & 255;
	}
	else if (u >> 16)
	{
		s[2] = u & 255;
		s[1] = u >> 8 & 255;
		s[0] = u >> 16 & 255;
	}
	else if (u >> 8)
	{
		s[1] = u & 255;
		s[0] = u >> 8 & 255;
	}
	else
		s[0] = u & 255;
	write(1, s, par[10]);
}

int		print_argument2(long long unsigned int u, int *par)
{
	char	s[5];
	int		i;

	i = -1;
	while (++i < 5)
		s[i] = '\0';
	if (par[9] == 'c')
	{
		if (par[8] == 0)
			write(1, &u, par[10]);
		else
			print_long_char(u, par, s);
	}
	else if (par[9] == 'u')
		print_nbr(0, u, 'u', par[10]);
	else if (par[9] == 'x' || par[9] == 'p')
		print_hex(u, 'x', par[10]);
	else if (par[9] == 'X')
		print_hex(u, 'X', par[10]);
	if (ft_find_char("cuxXp", par[9], 5) != 0)
		return (par[10]);
	return (0);
}
