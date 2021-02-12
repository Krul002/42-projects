/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:14:47 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 14:20:30 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) : ClapTrap(name, 100, 100, 120, 120, 1, 60, 20, 5) {
	this->setModel("SUPS1-TP");
	std::cout << this->getName() << " flew in from Krypton!" << std::endl;
}

SuperTrap::SuperTrap() : ClapTrap("_", 100, 100, 100, 100, 1, 30, 20, 5) {
	this->setModel("SUPS1-TP");
	std::cout << this->getName() << " flew in from Krypton!" << std::endl;
}

SuperTrap::~SuperTrap() {
	this->setModel("SUPS1-TP");
	std::cout << this->getName() << " returned to reborn Krypton!" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &ninja) {
	*this = ninja;
	this->setModel("SUPS1-TP");
	std::cout << this->getName() << " flew in from Krypton!" << std::endl;
}

SuperTrap			&SuperTrap::operator=(const SuperTrap &super) {
	std::cout << "Assignation operator called" << std::endl;
	FragTrap::operator=(super);
	NinjaTrap::operator=(super);
	return (*this);
}

std::string	SuperTrap::damage(std::string target, std::string mode, unsigned int amount) {
	std::string	s;
	if (mode == "range") {
		s.append(" throws a snowball into [\033[1;33m");
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
		s.append(" touched the green stone, he takes [\033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m] damage.");
	}
	return (s);
}

std::string	SuperTrap::reparo(unsigned int amount) {
	std::string	s;
	s.append(" flew into the sun, his health is restored by [\033[1;32m");
	s.append(std::to_string(amount));
	s.append("\033[0m] points!");
	return (s);
}

std::string	SuperTrap::notEnergy() {
	std::string	s;
	s.append(" is too lazy to do anything.");
	return (s);
}

std::string	SuperTrap::destroy(int n) {
	std::string	s;
	if (n == 1) {
		s.append(" swallowed kryptonite, let's honor his memory with a minute of silence.");
	}
	if (n == 2) {
		s.append("'s still dead, wait for the next release!");
	}
	return (s);
}
