/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:43:55 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 10:52:51 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &arg1, T &arg2) {
	T	cpy = arg1;
	arg1 = arg2;
	arg2 = cpy;
}

template<typename T>
T	&min(T &arg1, T &arg2) {
	if (arg1 < arg2)
		return arg1;
	return arg2;
}

template<typename T>
T	&max(T &arg1, T &arg2) {
	if (arg1 > arg2)
		return arg1;
	return arg2;
}

#endif
