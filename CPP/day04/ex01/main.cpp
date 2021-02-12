/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:05:40 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 03:05:34 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "Standart Test:" << std::endl << std::endl;
	{
		Character* me = new Character("me");
		std::cout << *me;
		Enemy* b = new RadScorpion();
		AWeapon* pr = new PlasmaRifle();
		AWeapon* pf = new PowerFist();
		me->equip(pr);
		std::cout << *me;
		me->equip(pf);
		me->attack(b);
		std::cout << *me;
		me->equip(pr);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		me->attack(b);
		std::cout << *me;
		delete me;
		delete pr;
		delete pf;
	}
	std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "My Test:" << std::endl << std::endl;
	{
		Character	*rick = new Character("Ricki");
		std::cout << *rick;
		Enemy	*scorp = new RadScorpion();
		Enemy	*mutant = new SuperMutant();
		AWeapon* rifle = new PlasmaRifle();
		AWeapon* fist = new PowerFist();
		rick->equip(rifle);
		std::cout << *rick;
		rick->attack(scorp);
		rick->attack(scorp);
		rick->attack(scorp);
		rick->attack(scorp);
		rick->attack(scorp);
		std::cout << *rick;
		rick->equip(fist);
		rick->attack(mutant);
		rick->recoverAP();
		rick->recoverAP();
		rick->recoverAP();
		std::cout << *rick;
		rick->attack(mutant);
		rick->attack(mutant);
		rick->attack(mutant);
		std::cout << *rick;
		delete rick;
		delete rifle;
		delete fist;
	}
	return (0);
}