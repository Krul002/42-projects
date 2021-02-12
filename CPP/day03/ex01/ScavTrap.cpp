/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:27:57 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:44:57 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

std::ostream	&ScavTrap::nameCout(void) {
	return (std::cout << "CL4P-TP<\033[1;34m" << Name << "\033[0m> ");
}

const std::string	ScavTrap::damage(unsigned int amount) {
	std::string	s;
	s.append("\033[1;31m");
	s.append(std::to_string(amount));
	s.append("\033[0m");
	return (s);
}
const std::string		ScavTrap::target(std::string const & target) {
	std::string	s;
	s.append("[\033[1;33m");
	s.append(target);
	s.append("\033[0m]");
	return (s);
}

ScavTrap::ScavTrap(const ScavTrap &scav) {
	std::cout << "Copy construct ScavTrap " << scav.Name << std::endl;
	*this = scav;
}

ScavTrap			&ScavTrap::operator=(const ScavTrap &scav) {
	std::cout << "Assignation operator called" << std::endl;
	this->Name = scav.Name;
	this->HP = scav.HP;
	this->EP = scav.EP;
	this->MaxHP = scav.MaxHP;
	this->MaxEP = scav.MaxEP;
	this->rangedAttackDamage = scav.rangedAttackDamage;
	this->meleeAttackDamage = scav.meleeAttackDamage;
	this->Lvl = scav.Lvl;
	this->reductArmorDamage = scav.reductArmorDamage;
	return (*this);
}

ScavTrap::ScavTrap() {
	Name = "_";
	nameCout() << "released from the factory" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 50;
	MaxEP = 50;
	Lvl = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	reductArmorDamage = 3;
}

ScavTrap::ScavTrap(std::string name) {
	Name = name;
	nameCout() << "released from the factory" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 50;
	MaxEP = 50;
	Lvl = 1;
	meleeAttackDamage = 20;
	rangedAttackDamage = 15;
	reductArmorDamage = 3;
}

ScavTrap::~ScavTrap() {
	nameCout() << "sent to manufacturer" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const &target) {
	nameCout() << "suddenly pulls out a flamethrower and fries the " << this->target(target) << "!";
	std::cout << " ( " << target << " takes " << this->damage(rangedAttackDamage) << " damage )" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const &target) {
	nameCout() << "beats the " << this->target(target) << " with a bat!";
	std::cout << " ( " << target << " takes " << this->damage(meleeAttackDamage) << " damage )" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	amount -= reductArmorDamage;
	if (HP == 0) {
		nameCout() << "became scrap metal and no longer takes damage!" << std::endl;
	}
	else {
		if (HP < amount)
			HP = 0;
		else
			HP -= amount;
		nameCout() << "gets hit in the head with a baseball, he takes " << this->damage(amount) << " damage." << std::endl;
		std::cout << "\t";
		nameCout() << "\033[1;35m" << HP << "\033[0m" << " hp left" << std::endl;
		if (HP == 0) {
			std::cout << "\t\t";
			nameCout() << "won't play baseball anymore" << std::endl;
		}
	}
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (amount > EP) {
		nameCout() << "spent all the healing, he needs to go to the store!" << std::endl;
	}
	else {
		if (HP + amount > MaxHP)
			amount = MaxHP - HP;
		nameCout() << "drinks a healing potion, his health is restored by " << this->damage(amount) << " points" << std::endl;
		HP += amount;
		EP -= amount;
	}
	std::cout << "\t";
	nameCout() << "has \033[1;35m" << HP << "\033[0m hp and \033[1;35m" << EP << "\033[0m ep"  << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target) {
	int		random = rand() % 5;
	std::string	challenge[] = {"Hunger Games", "Fatal Point(21)", "Game of Throne", "Gvint", "Hearth Stone"};
	nameCout() << "chalenged " << this->target(target) << " with " << this->target(challenge[random]) << "." << std::endl;
}