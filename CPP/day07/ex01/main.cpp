/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:30:41 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 11:31:37 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	func1(char &elem) {
	elem = 'a';
}

void	func2(int &elem) {
	elem = 10;
}

int		main() {
	int		i[] = {1, 2, 3, 4, 5, 6, 7};
	iter(i, 7, func);
	for (int j = 0; j < 7; j++) {
		std::cout << i[j];
		if (j + 1 != 7)
			std::cout << ";";
	}
	std::cout << std::endl;
	return 0;
}
