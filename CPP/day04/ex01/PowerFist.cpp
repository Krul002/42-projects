/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:20:33 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:24:37 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50) {
}

PowerFist::PowerFist(const PowerFist &waepon) {
	*this = waepon;
}

PowerFist	&PowerFist::operator=(const PowerFist &weapon) {
	AWeapon::operator=(weapon);
	return (*this);
}

PowerFist::~PowerFist() {
}

void		PowerFist::attack() const {
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
