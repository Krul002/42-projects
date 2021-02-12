/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:19:16 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:19:32 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &waepon) {
	*this = waepon;
}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &weapon) {
	AWeapon::operator=(weapon);
	return (*this);
}

PlasmaRifle::~PlasmaRifle() {
}

void		PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
