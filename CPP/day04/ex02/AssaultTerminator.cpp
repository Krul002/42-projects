/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:36:27 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 00:36:47 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &terminator) {
	*this = terminator;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator	&AssaultTerminator::operator=(const AssaultTerminator &terminator) {
	(void)terminator;
	return (*this);
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator	*AssaultTerminator::clone() const {
	AssaultTerminator	*copy = new AssaultTerminator(*this);
	return (copy);
}

void			AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void			AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void			AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}
