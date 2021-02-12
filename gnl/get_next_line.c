/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:15:02 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/16 21:15:06 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *s1, char *s2)
{
	if (s1 != 0)
		free(s1);
	if (s2 != 0)
		free(s2);
	return (0);
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
		return (ft_free(s1, 0));
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

	if ((buf = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (ft_free(mem, 0));
	i = 0;
	*n = 1;
	while (*n > 0 && mem[i] != '\n')
	{
		buf = ft_memset(buf, '\0', BUFFER_SIZE + 1);
		if ((*n = read(fd, buf, BUFFER_SIZE)) < 0)
			return (ft_free(buf, mem));
		if ((mem = ft_strjoin(mem, buf, -1, 0)) == 0)
			return (ft_free(buf, 0));
		while (mem[i] != '\n' && mem[i] != '\0')
			i++;
	}
	free(buf);
	if ((*line = ft_strjoin(0, mem, i, 0)) == 0)
		return (ft_free(mem, 0));
	*n = (mem[i] != '\n' && *n == 0) ? 0 : 1;
	i = (mem[i] == '\n') ? i : i - 1;
	return (ft_strjoin(mem, 0, -1, i + 1));
}

int		get_next_line(int fd, char **line)
{
	int				n;
	static char		*mem;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (mem == 0)
		mem = ft_strjoin(0, 0, -1, 0);
	if (mem == 0)
		return (-1);
	if ((mem = ft_buffer(mem, fd, &n, line)) == 0)
		return (-1);
	if (n == 0)
		mem = ft_free(mem, 0);
	return (n);
}
