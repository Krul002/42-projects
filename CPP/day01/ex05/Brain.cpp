/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 22:57:28 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/05 22:57:37 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string Brain::identify() {
	std::stringstream	s;
	s << std::hex << std::showbase << std::uppercase << (long)this;
	return (s.str());
}

Brain::Brain() {
	std::cout << "\033[1;32mNew brain!\033[0m" << std::endl;
}

Brain::~Brain() {
	std::cout << "\033[1;31mBye, bye brain(\033[0m" << std::endl;
}
