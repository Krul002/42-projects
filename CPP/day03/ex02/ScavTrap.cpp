/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:48:52 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 14:17:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 100, 50, 50, 1, 20, 15, 3) {
	this->setModel("CL4P-TP");
	std::cout << this->getName() << " released from the factory!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("_", 100, 100, 50, 50, 1, 20, 15, 3) {
	this->setModel("CL4P-TP");
	std::cout << this->getName() << " released from the factory!" << std::endl;
}

ScavTrap::~ScavTrap() {
	this->setModel("CL4P-TP");
	std::cout << this->getName() << " sent to manufacturer!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scav) {
	*this = scav;
	this->setModel("CL4P-TP");
	std::cout << this->getName() << " released from the factory!" << std::endl;
}

std::string	ScavTrap::damage(std::string target, std::string mode, unsigned int amount) {
	std::string	s;
	if (mode == "range") {
		s.append(" suddenly pulls out a flamethrower and fries the [\033[1;33m");
		s.append(target);
		s.append("\033[0m]! ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "melee") {
		s.append(" beats the [\033[1;33m");
		s.append(target);
		s.append("\033[0m] with a bat! ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "take") {
		s.append(" gets hit in the head with a baseball, he takes [\033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m] damage.");
	}
	return (s);
}

std::string	ScavTrap::reparo(unsigned int amount) {
	std::string	s;
	s.append(" drinks a healing potion, his health is restored by [\033[1;32m");
	s.append(std::to_string(amount));
	s.append("\033[0m] points!");
	return (s);
}

std::string	ScavTrap::notEnergy() {
	std::string	s;
	s.append(" spent all the healing, he needs to go to the store!");
	return (s);
}

std::string	ScavTrap::destroy(int n) {
	std::string	s;
	if (n == 1) {
		s.append(" won't play baseball anymore!");
	}
	if (n == 2) {
		s.append(" became scrap metal and no longer takes damage!");
	}
	return (s);
}

void	ScavTrap::challengeNewcomer(std::string const & target) {
	int		random = rand() % 5;
	std::string	challenge[] = {"Hunger Games", "Fatal Point(21)", "Game of Throne", "Gvint", "Hearth Stone"};
	std::cout << this->getName() << " chalenged [\033[1;33m" << target << "\033[0m] with [\033[1;33m" << challenge[random] << "\033[0m]." << std::endl;
}

ScavTrap			&ScavTrap::operator=(const ScavTrap &scav) {
	std::cout << "Assignation operator called" << std::endl;
	ClapTrap::operator=(scav);
	return (*this);
}
