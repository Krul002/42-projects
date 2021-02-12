/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:22:38 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:22:56 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &mat) {
	*this = mat;
}

MateriaSource		&MateriaSource::operator=(const MateriaSource &mat) {
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
		if (mat.inventory[i] != NULL)
			this->inventory[i] = mat.inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			delete this->inventory[i];
		this->inventory[i] = NULL;
	}
}

void				MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			this->inventory[i] = m;
			i = 4;
		}

	}
}

AMateria			*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL && this->inventory[i]->getType() == type) {
			return (this->inventory[i]->clone());
		}
	}
	return (NULL);
}
