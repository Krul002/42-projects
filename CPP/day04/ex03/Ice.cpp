/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:22:08 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:22:28 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice &mat) {
	*this = mat;
}

Ice			&Ice::operator=(const Ice &mat) {
	AMateria::operator=(mat);
	return (*this);
}

Ice::~Ice() {
}

void		Ice::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice			*Ice::clone() const {
	Ice		*ice = new Ice;
	return (ice);
}
