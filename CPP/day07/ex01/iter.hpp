/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:30:05 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 11:30:31 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T *arr, size_t len, void (*f)(T &elem)) {
	if (arr != NULL) 
		for (size_t i = 0; i < len; i++)
			f(arr[i]);
}

template<typename T>
void	func(T &elem) {
	elem += 1;
}

#endif
