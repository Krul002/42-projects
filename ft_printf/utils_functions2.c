/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:40:14 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/14 20:40:19 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_find_char(char *s, char c, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_nbrlen(long long int d, long long unsigned int u, int del)
{
	int		len;

	len = 1;
	while (d / del || u / del)
	{
		len++;
		d /= del;
		u /= del;
	}
	return (len);
}

void	print_nbr(long long int d, long long unsigned int u, int arg, int len)
{
	int						ci;
	unsigned int			cu;
	long long int			deli;
	long long unsigned int	delu;
	int						i;

	deli = 1;
	delu = 1;
	i = (len > 0) ? len - 1 : len;
	while (i--)
	{
		deli *= 10;
		delu *= 10;
	}
	while (len--)
	{
		ci = d / deli + '0';
		cu = u / delu + '0';
		i = (arg == 'i') ? write(1, &ci, 1) : write(1, &cu, 1);
		u -= (u / delu) * delu;
		d -= (d / deli) * deli;
		deli /= 10;
		delu /= 10;
	}
}

void	print_hex(long long unsigned int u, int arg, int len)
{
	unsigned int			c;
	long long unsigned int	del;
	int						i;

	del = 1;
	i = (len > 0) ? len - 1 : len;
	while (i--)
		del *= 16;
	while (len--)
	{
		del = (del == 0) ? 1 : del;
		c = u / del + '0';
		c = (u / del > 9) ? (u / del) + 'a' - 10 - ('x' - arg) : c;
		write(1, &c, 1);
		u -= (u / del) * del;
		del /= 16;
	}
}
