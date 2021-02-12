/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:20:48 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:21:07 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {
	this->name = "_";
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string name) {
	this->name = name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(const Character &character) {
	*this = character;
}

Character		&Character::operator=(const Character &character) {
	this->name = character.name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
		if (character.inventory[i] != NULL)
			this->inventory[i] = character.inventory[i]->clone();
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

std::string const	&Character::getName() const {
	return (this->name);
}

void				Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			i = 4;
		}
	}
}

void				Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		this->inventory[idx] = NULL;
}

void				Character::use(int idx, ICharacter &target) {
	if (idx >= 0 && idx <= 3 && this->inventory[idx] != NULL)
		this->inventory[idx]->use(target);
}
