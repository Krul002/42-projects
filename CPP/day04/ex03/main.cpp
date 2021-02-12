/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:45:19 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 14:43:10 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "Standart Tests:" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "My Tests:" << std::endl;
	{
		IMateriaSource	*materia = new MateriaSource();
		materia->learnMateria(new Ice());
		materia->learnMateria(new Cure());
		AMateria	*inventory;
		ICharacter	*sam = new Character("Sam");
		inventory = materia->createMateria("ice");
		sam->equip(inventory);
		std::cout << "\033[1;35mSam try use 1st skill:\n\033[1;34m";
		sam->use(0, *sam);
		sam->unequip(0);
		std::cout << "\033[1;35mSam try use 1st skill:\n\033[1;34m";
		sam->use(0, *sam);
		delete inventory;
		inventory = materia->createMateria("cure");
		sam->equip(inventory);
		inventory = materia->createMateria("ice");
		sam->equip(inventory);
		std::cout << "\033[1;35mSam try use 2nd skill:\n\033[1;34m";
		sam->use(1, *sam);
		std::cout << "\033[1;35mSam try use 1st skill:\n\033[1;33m";
		sam->use(0, *sam);
		std::cout << "\033[0m";
		delete sam;
		delete materia;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	return 0;
}