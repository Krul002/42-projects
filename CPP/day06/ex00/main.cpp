/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 07:20:02 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 07:21:36 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int		main(int size, char **args) {
	if (size == 1)
		return (0);
	Scalar	sc;
	for (int i = 1; i < size; i++) {
		std::string s(args[i]);
		sc.getNumbers(s);
		if (i + 1 < size)
			std::cout << std::endl;
	}
	return (0);
}
