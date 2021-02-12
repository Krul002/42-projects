/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:17:22 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:17:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() {
	this->name = "_";
	this->apcost = 0;
	this->damage = 0;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) {
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}

AWeapon::AWeapon(const AWeapon &waepon) {
	*this = waepon;
}

AWeapon	&AWeapon::operator=(const AWeapon &weapon) {
	this->name = weapon.name;
	this->apcost = weapon.apcost;
	this->damage = weapon.damage;
	return (*this);
}

AWeapon::~AWeapon() {
}

int		AWeapon::getAPCost() const {
	return (this->apcost);
}

int		AWeapon::getDamage() const {
	return (this->damage);
}

const std::string AWeapon::getName() const {
	return (this->name);
}
