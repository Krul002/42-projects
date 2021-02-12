/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:17:31 by cmalt             #+#    #+#             */
/*   Updated: 2020/06/05 21:17:34 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int		ft_atoi(const char *arr)
{
	int		n;
	int		i;
	int		nbr;

	n = 1;
	i = 0;
	nbr = 0;
	while (arr[i] == '\t' || arr[i] == '\v' || arr[i] == '\r' || \
	arr[i] == '\f' || arr[i] == '\n' || arr[i] == ' ')
		i++;
	if (arr[i] == '-')
		n = -1;
	if (arr[i] == '-' || arr[i] == '+')
		i++;
	while (arr[i] >= '0' && arr[i] <= '9')
		nbr = nbr * 10 + (arr[i++] - 48);
	return (nbr * n);
}

char	*ft_itoa(int i)
{
	int		len;
	char	*str;
	int		n;

	str = 0;
	n = i;
	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[len] = '\0';
	while (len - 1 >= 0)
	{
		str[len - 1] = i % 10 + '0';
		i /= 10;
		len--;
	}
	return (str);
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
