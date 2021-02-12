/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:15:23 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/16 21:15:27 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_memset(void *destination, int c, int n)
{
	int		i;
	char	*d;
	char	ch;

	i = 0;
	d = (char *)destination;
	ch = (char)c;
	while (i < n)
	{
		d[i] = ch;
		i++;
	}
	return (destination);
}
