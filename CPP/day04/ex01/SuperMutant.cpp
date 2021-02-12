/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:23:04 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:23:22 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &enemy) {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	*this = enemy;
}

SuperMutant	&SuperMutant::operator=(const SuperMutant &enemy) {
	Enemy::operator=(enemy);
	return (*this);
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

void	SuperMutant::takeDamage(int damage) {
	if (damage < 0 && damage - 3 > 0)
		damage = 0;
	Enemy::takeDamage(damage - 3);
}
