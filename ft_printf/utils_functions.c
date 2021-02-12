/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:35:59 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/14 14:36:03 by cmalt            ###   ########.fr       */
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

void	ft_plus_minus_resh_space(int *par, long long int d)
{
	if (par[1] > 0)
	{
		par[6] += par[5];
		par[5] = 0;
		if (par[6] > 0)
		{
			if (par[3] > 0 || par[2] > 0 || d < 0)
				par[6] -= 1;
			if ((par[4] > 0 || par[9] == 'p') && par[6] > 1)
				par[6] -= 2;
			else if (par[4] > 0 || par[9] == 'p')
				par[6] -= 1;
		}
	}
	if (par[5] > 0)
	{
		if (par[3] > 0 || par[2] > 0 || d < 0)
			par[5] -= 1;
		if ((par[4] > 0 || par[9] == 'p') && par[5] > 1)
			par[5] -= 2;
		else if (par[4] > 0 || par[9] == 'p')
			par[5] -= 1;
	}
}

void	ft_width_acc_len(int *par, long long unsigned int u, long long int d)
{
	if (par[7] > 0 && par[9] == 's' && par[6] < par[10])
	{
		par[10] = par[6];
		par[6] = 0;
	}
	else if (par[9] == 's')
		par[6] = 0;
	if (par[9] == 'c' || par[9] == '%')
		par[6] = 0;
	if (par[6] == 0 && par[7] > 0)
	{
		if (ft_find_char("uxXp", par[9], 4) != 0 && u == 0)
			par[10] = 0;
		if ((par[9] == 'd' || par[9] == 'i') && d == 0)
			par[10] = 0;
	}
	par[6] = (par[7] > 0 && par[6] > par[10]) ? par[6] - par[10] : 0;
	par[5] = (par[5] > (par[6] + par[10])) ? par[5] - (par[6] + par[10]) : 0;
	ft_plus_minus_resh_space(par, d);
}

void	ft_off_par(int *par, long long unsigned int u, long long int d)
{
	if (ft_find_char("scup%", par[9], 5) != 0)
	{
		par[2] = 0;
		par[3] = 0;
		par[4] = 0;
	}
	if (par[9] == 'd' || par[9] == 'i')
		par[4] = 0;
	if (par[9] == 'x' || par[9] == 'X')
	{
		par[2] = 0;
		par[3] = 0;
	}
	if ((par[9] == 'c' || par[9] == 's') && (par[8] < 3 || par[8] > 3))
		par[8] = 0;
	if ((par[9] == 'p' || par[9] == '%') && par[8] > 0)
		par[8] = 0;
	if ((ft_find_char("diuxX", par[9], 5) != 0 && par[7] > 0) || par[0] > 0)
		par[1] = 0;
	if (par[2] > 0)
		par[3] = 0;
	if ((par[9] == 'x' || par[9] == 'X') && u == 0)
		par[4] = 0;
	ft_width_acc_len(par, u, d);
}
