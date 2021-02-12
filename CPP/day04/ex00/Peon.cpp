/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:55:15 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 15:55:21 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon() : Victim() {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string	name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &peon) {
	std::cout << "Copy peon " << this->getName() << "!" << std::endl;
	*this = peon;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
	std::cout << "Bleuark..." << std::endl;
}

Peon	&Peon::operator=(const Peon &peon) {
	std::cout << "Assignation operator called" << std::endl;
	Victim::operator=(peon);
	return (*this);
}

void	Peon::getPolymorphed() const {
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}
