/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:03:16 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:01:35 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weap(weapon) {
	this->name = name;
	std::cout << "\033[1;32mNew HumanA!\033[0m" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "\033[1;31mDelete HumanA!\033[0m" << std::endl;
}

void	HumanA::attack() {
	std::cout << "\033[1;33m\t" << this->name << " attacks with his " << this->weap.getType() << std::endl;
}
