/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width_accuracy_mod.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:48:22 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:48:29 by cmalt            ###   ########.fr       */
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

void	ft_zero_par(int *par)
{
	par[0] = -1;
	par[1] = 0;
	par[2] = 0;
	par[3] = 0;
	par[4] = 0;
	par[5] = 0;
	par[6] = 0;
	par[7] = 0;
	par[8] = 0;
	par[9] = 0;
	par[10] = 0;
}

int		flags(char *s, int i, int *par)
{
	char	c;

	c = s[i];
	while (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
	{
		par[0] = (c == '-') ? 1 : par[0];
		par[1] = (c == '0') ? 1 : par[1];
		par[2] = (c == '+') ? 1 : par[2];
		par[3] = (c == ' ') ? 1 : par[3];
		par[4] = (c == '#') ? 1 : par[4];
		i++;
		c = s[i];
	}
	return (i);
}

int		width(char *s, int i, int *par, va_list ap)
{
	int	nbr;

	nbr = 0;
	if (s[i] == '*' && i++)
		nbr = va_arg(ap, int);
	while (s[i - 1] != '*' && s[i] >= '0' && s[i] <= '9')
		nbr = nbr * 10 + s[i++] - '0';
	if (nbr < 0)
	{
		par[0] = 1;
		nbr *= -1;
	}
	par[5] = nbr;
	return (i);
}

int		accuracy(char *s, int i, int *par, va_list ap)
{
	int	nbr;

	nbr = 0;
	par[7] = 1;
	if (s[i] == '*' && i++)
		nbr = va_arg(ap, int);
	while (s[i - 1] != '*' && s[i] == '0')
		i++;
	while (s[i - 1] != '*' && s[i] >= '0' && s[i] <= '9')
		nbr = nbr * 10 + s[i++] - '0';
	if (nbr < 0)
	{
		par[7] = 0;
		nbr = 0;
	}
	par[6] = nbr;
	return (i);
}

int		mod(char *s, int i, int *par)
{
	if (s[i] == 'h' && i++)
	{
		par[8] = 1;
		if (s[i] == 'h' && i++)
			par[8] = 2;
	}
	else if (s[i] == 'l' && i++)
	{
		par[8] = 3;
		if (s[i] == 'l' && i++)
			par[8] = 4;
	}
	return (i);
}
