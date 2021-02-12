/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:02:30 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/06 12:02:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
	std::cout << "\033[1;32mNew Weapon!\033[0m" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "\033[1;31mDelete weapon: " << _type << "\033[0m" << std::endl;
}

void				Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string&	Weapon::getType() {
	return (this->_type);
}
