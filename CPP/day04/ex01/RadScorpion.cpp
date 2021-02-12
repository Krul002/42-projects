/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:22:03 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:22:54 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &enemy) {
	std::cout << "* click click click *" << std::endl;
	*this = enemy;
}

RadScorpion	&RadScorpion::operator=(const RadScorpion &enemy) {
	Enemy::operator=(enemy);
	return (*this);
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}

void	RadScorpion::takeDamage(int damage) {
	if (damage < 0 && damage - 3 > 0)
		damage = 0;
	Enemy::takeDamage(damage - 3);
}
