/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 08:14:19 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/23 07:52:07 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void	*serialize(void) {
	char		*arr = new char[20];
	std::string	alphaDigit = "absdefghijklmnopqrstuvwxyzABSDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	for (int i = 0; i < 8; i++) {
		arr[i] = alphaDigit[rand() % alphaDigit.length()];
		arr[i + 12] = alphaDigit[rand() % alphaDigit.length()];
	}
	char	*arr1 = arr + 8;
	int		random = rand() % alphaDigit.length();
	*(reinterpret_cast<int*>(arr1)) = random;
	return (arr);
}

Data	*deserialize(void *raw) {
	Data	*data = new Data;
	char	*arr = static_cast<char*>(raw);
	data->s1 =  std::string(arr, 8);
	data->n = *(reinterpret_cast<int*>(arr + 8));
	data->s2 =  std::string(arr + 12, 8);
	return (data);
}
