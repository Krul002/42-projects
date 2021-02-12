/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:18:16 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 03:01:06 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void	Character::attack(Enemy *enemy) {
	if (enemy != NULL && weapon != NULL && this->AP >= this->weapon->getAPCost()) {
		std::cout << this->name << " attacks " << enemy->getType() << " with a " << this->weapon->getName() << std::endl;
		this->AP -= this->weapon->getAPCost();
		this->weapon->attack();
		enemy->takeDamage(this->weapon->getDamage());
		if (enemy->getHP() <= 0) {
			delete enemy;
			enemy = NULL;
		}
	}
}

void	Character::recoverAP() {
	if (AP > 31)
		AP = 40;
	else
		AP += 10;
}

void	Character::equip(AWeapon *weapon) {
	this->weapon = weapon;
}

const	std::string	Character::getName() const {
	return (this->name);
}

std::string		Character::getStatus() const {
	std::string	s;
	s = this->name;
	s += " has ";
	s += std::to_string(this->AP);
	s += " AP and ";
	if (weapon != NULL) {
		s += "wields a ";
		s += weapon->getName();
		s += "\n";
	}
	else {
		s += "is unarmed\n";
	}
	return (s);
}

Character::Character() {
	this->name = "_";
	this->AP = 40;
	this->weapon = NULL;
}

Character::Character(std::string const &name) {
	this->name = name;
	this->AP = 40;
	this->weapon = NULL;
}

Character::Character(const Character &character) {
	*this = character;
}

Character	&Character::operator=(const Character &character) {
	this->name = character.name;
	this->AP = character.AP;
	this->weapon = character.weapon;
	return (*this);
}

Character::~Character() {
}

std::ostream	&operator<<(std::ostream &fd, const Character &character) {
	return (fd << character.getStatus());
}
