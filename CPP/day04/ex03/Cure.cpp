/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:21:21 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:21:45 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure &mat) {
	*this = mat;
}

Cure			&Cure::operator=(const Cure &mat) {
	AMateria::operator=(mat);
	return (*this);
}

Cure::~Cure() {
}

void		Cure::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure			*Cure::clone() const {
	Cure		*cure = new Cure;
	return (cure);
}
