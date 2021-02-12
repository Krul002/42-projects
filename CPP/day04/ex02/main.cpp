/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:31:32 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 14:37:17 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main() {
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "Standart Tests:" << std::endl;
	{
		ISpaceMarine	*bob = new TacticalMarine;
		ISpaceMarine	*jim = new AssaultTerminator;
		ISquad	*vlc = new Squad;
		vlc->push(bob);
		vlc->push(jim);
		std::cout << std::endl;
		for (int i = 0; i < vlc->getCount(); ++i) {
			ISpaceMarine* cur = vlc->getUnit(i);
			cur->battleCry();
			cur->rangedAttack();
			cur->meleeAttack();
			std::cout << std::endl;
		}
		delete vlc;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "My Tests:" << std::endl;
	{
		std::cout << "\033[1;32m" << std::endl;
		ISpaceMarine	*unit_1 = new TacticalMarine;
		std::cout << "\033[1;31m" << std::endl;
		ISpaceMarine	*unit_2 = new AssaultTerminator;
		std::cout << "\033[1;32m" << std::endl;
		ISpaceMarine	*unit_3 = new TacticalMarine;
		ISpaceMarine	*unit_4 = new TacticalMarine;
		std::cout << "\033[1;31m" << std::endl;
		ISpaceMarine	*unit_5 = new AssaultTerminator;
		ISpaceMarine	*unit_6 = new AssaultTerminator;
		std::cout << "\033[1;32m" << std::endl;
		ISpaceMarine	*unit_7 = new TacticalMarine;
		ISquad	*squad = new Squad;
		squad->push(unit_1);
		squad->push(unit_2);
		squad->push(unit_3);
		squad->push(unit_4);
		squad->push(unit_5);
		squad->push(unit_6);
		squad->push(unit_7);
		for (int i = 0; i < squad->getCount(); i++) {
			if (i == 0 || i == 2 || i == 3 || i == 6)
				std::cout << "\033[1;34m" << std::endl;
			else
				std::cout << "\033[1;33m" << std::endl;
			squad->getUnit(i)->battleCry();
			squad->getUnit(i)->rangedAttack();
			squad->getUnit(i)->meleeAttack();
		}
		std::cout << "\033[1;30m" << std::endl;
		delete squad;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	return 0;
}
