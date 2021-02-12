/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:37:28 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 00:37:42 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine &tacmar) {
	*this = tacmar;
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine	&TacticalMarine::operator=(const TacticalMarine &tacmar) {
	(void)tacmar;
	return (*this);
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh..." << std::endl;
}

TacticalMarine	*TacticalMarine::clone() const {
	TacticalMarine	*copy = new TacticalMarine(*this);
	return (copy);
}

void			TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT!" << std::endl;
}

void			TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with a bolter *" << std::endl;
}

void			TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with a chainsword *" << std::endl;
}
