/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:47:54 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 14:19:53 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 100, 100, 1, 30, 20, 5) {
	this->setModel("FR4G-TP");
	std::cout << this->getName() << " created!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("_", 100, 100, 100, 100, 1, 30, 20, 5) {
	this->setModel("FR4G-TP");
	std::cout << this->getName() << " created!" << std::endl;
}

FragTrap::~FragTrap() {
	this->setModel("FR4G-TP");
	std::cout << this->getName() << " destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &frag) {
	*this = frag;
	this->setModel("FR4G-TP");
	std::cout << this->getName() << " created!" << std::endl;
}

std::string	FragTrap::damage(std::string target, std::string mode, unsigned int amount) {
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
		s.append(" hugs [\033[1;33m");
		s.append(target);
		s.append("\033[0m] in his arms! ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "take") {
		s.append(" hit by a meteorite, he takes [\033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m] damage.");
	}
	return (s);
}

std::string	FragTrap::reparo(unsigned int amount) {
	std::string	s;
	s.append(" drinks machine oil, his health is restored by [\033[1;32m");
	s.append(std::to_string(amount));
	s.append("\033[0m] points!");
	return (s);
}

std::string	FragTrap::notEnergy() {
	std::string	s;
	s.append(" does not have enough money for this procedure.");
	return (s);
}

std::string	FragTrap::destroy(int n) {
	std::string	s;
	if (n == 1) {
		s.append(" lost the remnants of his brain!");
	}
	if (n == 2) {
		s.append(" already destroyed, stop mocking the corpse!");
	}
	return (s);
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int		random = rand() % 6;
	unsigned int	EP;
	std::string	poke[] = {"Jolteon", "Swampert", "Torkoal", "Flygon", "Gardevoir", "Doublade"};
	std::string move[] = {"Thunderbolt", "Muddy Water", "Overheat", "Dragon Claw", "Psychic", "Night Slash"};
	unsigned int	damage[] = {90, 90, 130, 80, 90, 70};
	EP = getEnergy();
	if (EP >= 25) {
		EP -= 25;
		std::cout << this->getName() << " \"Go! [\033[1;33m" << poke[random] << "\033[0m]!" << std::endl;
		std::cout << "\t[\033[1;33m" << poke[random] << "\033[0m] used [\033[1;33m" << move[random] << "\033[0m]\"";
		std::cout << "[\033[1;33m" << target << "\033[0m] \033[1;31m" << std::to_string(damage[random]) << "\033[0m damage )" << std::endl;
	}
	else {
		std::cout << this->getName() << " does not have enough money for this procedure" << std::endl;
	}
	setEnergy(EP);
	std::cout << "\t" << this->getName() << " has \033[1;35m" << this->getHP() << "\033[0m hp and \033[1;35m" << EP << "\033[0m ep"  << std::endl;
}

FragTrap			&FragTrap::operator=(const FragTrap &frag) {
	std::cout << "Assignation operator called" << std::endl;
	ClapTrap::operator=(frag);
	return (*this);
}
