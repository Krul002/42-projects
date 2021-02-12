/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:17:10 by cmalt             #+#    #+#             */
/*   Updated: 2020/06/05 21:17:13 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_buffer(char *mem, int fd, int *n, char **line);
char	*ft_strjoin(char *s1, char *s2, int len, int i);
char	**ft_mem(char **mem, char *num, int i, int n);
char	**ft_free(char *s1, char *s2, char **s, int n);
int		ft_strlen(const char *s);
int		ft_atoi(const char *arr);
char	*ft_itoa(int i);
void	*ft_memset(void *destination, int c, int n);

#endif
