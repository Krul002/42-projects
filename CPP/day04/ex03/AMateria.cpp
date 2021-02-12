/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:19:45 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:20:14 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
	this->_type = "_";
	this->_xp = 0;
}

AMateria::AMateria(std::string const &type) {
	this->_type = type;
	this->_xp = 0;
}

AMateria::AMateria(const AMateria &mat) {
	*this = mat;
}

AMateria			&AMateria::operator=(const AMateria &mat) {
	this->_type = mat._type;
	this->_xp = mat._xp;
	return (*this);
}

AMateria::~AMateria() {
}

unsigned int		AMateria::getXP() const {
	return (this->_xp);
}

std::string const	&AMateria::getType() const {
	return (this->_type);
}

void		AMateria::use(ICharacter &target) {
	(void)target;
	this->_xp += 10;
}
