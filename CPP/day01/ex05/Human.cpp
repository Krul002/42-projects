/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:57:53 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/06 10:29:24 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Brain	&Human::getBrain() {
	return (brain);
}

std::string Human::identify() {
	return (brain.identify());
}

Human::Human() {
	std::cout << "\033[1;32mNew human!\033[0m" << std::endl;
}

Human::~Human() {
	std::cout << "\033[1;31mBye, bye human(\033[0m" << std::endl;
}
