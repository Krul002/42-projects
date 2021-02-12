/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:15:46 by cmalt             #+#    #+#             */
/*   Updated: 2020/05/16 21:15:50 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_buffer(char *mem, int fd, int *n, char **line);
char	*ft_strjoin(char *s1, char *s2, int len, int i);
char	*ft_free(char *s1, char *s2);
int		ft_strlen(const char *s);
void	*ft_memset(void *destination, int c, int n);

#endif
