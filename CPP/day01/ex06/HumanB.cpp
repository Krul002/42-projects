/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:04:53 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:01:49 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	std::cout << "\033[1;32mNew HumanB!\033[0m" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "\033[1;31mDelete HumanB!\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weap = &weapon;
}

void	HumanB::attack() {
	std::cout << "\033[1;33m\t" << this->name << " attacks with his " << weap->getType() << std::endl;
}
