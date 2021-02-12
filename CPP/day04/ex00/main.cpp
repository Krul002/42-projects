/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:05:54 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:50:36 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
	std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "Standart Test:" << std::endl << std::endl;
	{
		Sorcerer	robert("Robert", "the Magnificent");
		Victim		jim("Jimmy");
		Peon		joe("Joe");
		std::cout << robert << jim << joe;
		robert.polymorph(jim);
		robert.polymorph(joe);
	}
	std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
	std::cout << "My Test:" << std::endl << std::endl;
	Sorcerer	mage("Zedicus zul ZOrander", "Mage of first rang");
	Victim		vilager("Villager");
	Peon		zog("ZOG");
	{
		std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
		Sorcerer	*mage1 = new Sorcerer("New-mage", "La-la-la");
		Victim		*vilager1 = new Victim("Seven");
		Peon		*zog1 = new Peon("Ku-ku");
		
		std::cout << *mage1 << *vilager1 << *zog1;

		mage1->polymorph(*vilager1);
		mage1->polymorph(*zog1);
		vilager1->getPolymorphed();
		zog1->getPolymorphed();

		delete mage1;
		delete zog1;
		delete vilager1;
		std::cout << "---------------------------------------------------------------------------------|----" << std::endl;
	}
	return (0);
}