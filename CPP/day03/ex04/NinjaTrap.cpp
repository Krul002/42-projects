/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 00:47:17 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 14:20:16 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name, 60, 60, 120, 120, 1, 60, 5, 0) {
	this->setModel("NJ7610-TP");
	std::cout << this->getName() << " woke up from Infinite Tsukuyomi!" << std::endl;
}

NinjaTrap::NinjaTrap() : ClapTrap("_", 60, 60, 120, 120, 1, 60, 5, 0) {
	this->setModel("NJ7610-TP");
	std::cout << this->getName() << " woke up from Infinite Tsukuyomi!" << std::endl;
}

NinjaTrap::~NinjaTrap() {
	this->setModel("NJ7610-TP");
	std::cout << this->getName() << "'s Infinite Tsukuyomi consumed!" << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &ninja) {
	*this = ninja;
	this->setModel("NJ7610-TP");
	std::cout << this->getName() << " woke up from Infinite Tsukuyomi!" << std::endl;
}

std::string	NinjaTrap::damage(std::string target, std::string mode, unsigned int amount) {
	std::string	s;
	if (mode == "range") {
		s.append(" throws Rasen Shuriken at [\033[1;33m");
		s.append(target);
		s.append("\033[0m]! ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "melee") {
		s.append(" uses taijutsu against [\033[1;33m");
		s.append(target);
		s.append("\033[0m]! ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "take") {
		s.append(" gets hit on the wall by \033[1;36mSakura\033[0m and takes [\033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m] damage.");
	}
	return (s);
}

std::string	NinjaTrap::reparo(unsigned int amount) {
	std::string	s;
	s.append(" eats ramen and restores [\033[1;32m");
	s.append(std::to_string(amount));
	s.append("\033[0m] health points!");
	return (s);
}

std::string	NinjaTrap::notEnergy() {
	std::string	s;
	s.append(" spent all his chakra!");
	return (s);
}

std::string	NinjaTrap::destroy(int n) {
	std::string	s;
	if (n == 1) {
		s.append(" died just like Jiraiya!");
	}
	if (n == 2) {
		s.append(" dead, bring user Edo Tensei here!");
	}
	return (s);
}

void	NinjaTrap::ninjaShoebox(ClapTrap &clap) {
	std::cout << this->getName() << " can't attack his master " << clap.getName() << " - it's a shame!" << std::endl;
}
void	NinjaTrap::ninjaShoebox(FragTrap &frap) {
	std::cout << this->getName() << " has faced a strong opponent, he is using the Bijuu Bomb!";
	std::cout << " ( [" << frap.getName() << "] \033[1;31m" << frap.getHP() * 10 << "\033[0m damage )" << std::endl;
	frap.setHP(0);
}
void	NinjaTrap::ninjaShoebox(ScavTrap &scav) {
	unsigned int	ep1;
	unsigned int	ep2;
	unsigned int	max;

	ep1 = this->getEnergy();
	ep2 = scav.getEnergy();
	max = this->getMaxEnergy();
	if (max > ep1) {
		if (ep2 >= max - ep1) {
			ep2 -= (max - ep1);
			ep1 = max;
		}
		else {
			ep1 += ep2;
			ep2 = 0;
		}
	}
	this->setEnergy(ep1);
	scav.setEnergy(ep2);
	std::cout << this->getName() << " is stealing the " << scav.getName() << " energy!";
	std::cout << " Now he has " << this->getEnergy() << " EP, and " << scav.getName() << " has " << scav.getEnergy() << " EP." << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &ninja) {
	std::cout << "Two equal opponents met and this battle lasted forever!" << std::endl;
	std::cout << "\tBut the " << ninja.getName() << " misses and " << this->getName() << " prompts!" << std::endl;
}

NinjaTrap			&NinjaTrap::operator=(const NinjaTrap &ninja) {
	std::cout << "Assignation operator called" << std::endl;
	ClapTrap::operator=(ninja);
	return (*this);
}
