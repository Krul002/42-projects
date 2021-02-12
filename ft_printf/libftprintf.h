/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:49:13 by cmalt             #+#    #+#             */
/*   Updated: 2020/07/07 17:49:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uchar;

int		ft_printf(const char *format, ...);
int		print_error(va_list ap, const char *str, int count);
int		set_param(char *s, int i, va_list ap, int *par);
void	ft_zero_par(int *par);
int		flags(char *s, int i, int *par);
int		ft_find_char(char *s, char c, int len);
int		width(char *s, int i, int *par, va_list ap);
int		accuracy(char *s, int i, int *par, va_list ap);
int		mod(char *s, int i, int *par);
void	ft_va_arg1(char **s, va_list ap, int *par);
void	ft_va_arg2(long long int *d, va_list ap, int *par);
void	ft_va_arg3(long long unsigned int *u, va_list ap, int *par);
int		ft_nbrlen(long long int d, long long unsigned int u, int del);
void	ft_off_par(int *par, long long unsigned int u, long long int d);
int		ft_indent(int width, int *minus);
int		ft_accuracy(int acc, int *par, long long int *d);
int		print_argument1(char *s, long long int d, int *par);
void	print_nbr(long long int d, long long unsigned int u, int arg, int len);
int		print_argument2(long long unsigned int u, int *par);
void	print_hex(long long unsigned int u, int arg, int len);

#endif
