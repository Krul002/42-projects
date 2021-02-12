/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:36:59 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 13:41:05 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "ISpaceMarine.hpp"

Squad::Squad() {
	this->squad = NULL;
	this->size = 0;
}

Squad::Squad(const Squad &squad) {
	*this = squad;
}

Squad::~Squad() {
	for (int i = 0; i < this->size; i++) {
		delete squad[i];
	}
	if (this->squad != NULL)
		delete[] squad;
}

Squad					&Squad::operator=(const Squad &squad) {
	this->size = squad.size;
	this->squad = squad.squad;
	return (*this);
}

int						Squad::getCount() const {
	return (this->size);
}

ISpaceMarine			*Squad::getUnit(int i) const {
	return (this->squad[i]);
}

int						Squad::push(ISpaceMarine *squad) {
	if (squad == NULL)
		return (this->size);
	for (int i = 0; i < this->size; i++) {
		if (this->squad[i] == squad)
			return (this->size);
	}
	ISpaceMarine	**newSquad = new ISpaceMarine*[this->size + 1];
	for (int i = 0; i < this->size; i++) {
		newSquad[i] = this->squad[i];
	}
	delete[] this->squad;
	newSquad[this->size] = squad;
	this->squad = newSquad;
	this->size++;
	return (this->size);
}
