/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:16:41 by cmalt             #+#    #+#             */
/*   Updated: 2020/06/05 21:16:44 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	**ft_free(char *s1, char *s2, char **s, int n)
{
	int		i;

	if (s1 != 0)
		free(s1);
	if (s2 != 0)
		free(s2);
	i = 0;
	while (s != 0 && i < n)
	{
		free(s[i]);
		s[i] = 0;
		i++;
	}
	if (s != 0)
		free(s);
	return (0);
}

char	**ft_mem(char **mem, char *num, int i, int n)
{
	char	**copy;

	if (n > 0)
	{
		ft_free(mem[i + 1], 0, 0, 0);
		while (mem[++i] != 0 || --n > 0)
			mem[i] = mem[i + 1];
		if (mem[0] == 0)
			mem = ft_free(0, 0, mem, 0);
		return (mem);
	}
	copy = mem;
	if ((mem = (char **)malloc(sizeof(char *) * (i + 1))) == 0)
		return (copy);
	mem[i] = 0;
	while (mem != 0 && ++n < i - 1)
		if ((mem[n] = ft_strjoin(0, copy[n], -1, 0)) == 0)
			mem = ft_free(num, 0, mem, n);
	if (mem != 0 && (mem[i - 1] = ft_strjoin(num, "I", -1, 0)) == 0)
		mem = ft_free(0, 0, mem, i - 1);
	if (mem == 0)
		return (copy);
	ft_free(0, 0, copy, i - 1);
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2, int len, int i)
{
	int		len1;
	int		len2;
	char	*str;
	int		j;

	len1 = (s1 != 0) ? ft_strlen(&s1[i]) : 0;
	len2 = (s2 != 0) ? ft_strlen(s2) : 0;
	len = (len >= 0) ? len : len1 + len2;
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == 0)
		return ((char *)ft_free(s1, 0, 0, 0));
	j = 0;
	while (s1 != 0 && j < len && j < len1)
		str[j++] = s1[i++];
	i = 0;
	while (s2 != 0 && j < len && i < len2)
		str[j++] = s2[i++];
	if (s1 != 0)
		free(s1);
	while (j < len + 1)
		str[j++] = '\0';
	return (str);
}

char	*ft_buffer(char *mem, int fd, int *n, char **line)
{
	char	*buf;
	int		i;
	int		j;

	if ((buf = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return ((char *)ft_free(mem, 0, 0, 0));
	i = *n;
	j = i;
	while (*n > 0 && mem[i] != '\n')
	{
		buf = ft_memset(buf, '\0', BUFFER_SIZE + 1);
		if ((*n = read(fd, buf, BUFFER_SIZE)) < 0)
			return ((char *)ft_free(buf, mem, 0, 0));
		if ((mem = ft_strjoin(mem, buf, -1, 0)) == 0)
			return ((char *)ft_free(buf, 0, 0, 0));
		while (mem[i] != '\n' && mem[i] != '\0')
			i++;
	}
	free(buf);
	if ((*line = ft_strjoin(0, &mem[j], i - j, 0)) == 0)
		return ((char *)ft_free(mem, 0, 0, 0));
	*n = (mem[i] != '\n' && *n == 0) ? 0 : 1;
	i = (mem[i] == '\n') ? i : i - 1;
	mem[j] = '\0';
	return (ft_strjoin(mem, &mem[i + 1], -1, 0));
}

int		get_next_line(int fd, char **line)
{
	int				n;
	int				i;
	static char		**mem;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	i = 0;
	n = 0;
	while (mem != 0 && mem[i] != 0 && ft_atoi(mem[i]) != fd)
		i++;
	if (mem == 0 || mem[i] == 0)
		mem = ft_mem(mem, ft_itoa(fd), i + 1, -1);
	if (mem == 0 || mem[i] == 0)
		return (-1);
	while (mem[i][n] > 47 && mem[i][n] < 58)
		n++;
	n++;
	if ((mem[i] = ft_buffer(mem[i], fd, &n, line)) == 0)
	{
		mem = ft_mem(mem, 0, i - 1, 2);
		n = -1;
	}
	return ((n == 0 && (mem = ft_mem(mem, 0, i - 1, 1)) == 0) ? 0 : n);
}
