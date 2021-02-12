/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:47:15 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:45:20 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void		ClapTrap::setModel(std::string s) {
	Model = s;
}

std::string	ClapTrap::getName() {
	std::string	s;
	s.append(Model);
	s.append("<\033[1;34m");
	s.append(this->Name);
	s.append("\033[0m>");
	return (s);
}

unsigned int	ClapTrap::getHP() {
	return (HP);
}

void			ClapTrap::setHP(unsigned int amount) {
	HP = amount;
}

unsigned int	ClapTrap::getEnergy() {
	return (EP);
}

unsigned int	ClapTrap::getMaxEnergy() {
	return (MaxEP);
}

void		ClapTrap::setEnergy(unsigned int ep) {
	EP = ep;
}

ClapTrap::ClapTrap(std::string name) {
	Name = name;
	Model = "";
	std::cout << "Create new ClapTrap" << getName() << "!" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 100;
	MaxEP = 100;
	Lvl = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	reductArmorDamage = 5;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int maxHp, unsigned int ep, unsigned int maxEp, unsigned int lvl, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armor) {
	Name = name;
	Model = "";
	std::cout << "Create new ClapTrap" << getName() << "!" << std::endl;
	HP = hp;
	MaxHP = maxHp;
	EP = ep;
	MaxEP = maxEp;
	Lvl = lvl;
	meleeAttackDamage = meleeDamage;
	rangedAttackDamage = rangedDamage;
	reductArmorDamage = armor;
}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	*this = clap;
	std::cout << "Create copy ClapTrap<\033[1;34m" << clap.Name << "\033[0m>!" << std::endl;
}

ClapTrap		&ClapTrap::operator=(const ClapTrap &clap) {
	std::cout << "Assignation operator called" << std::endl;
	this->Name = clap.Name;
	this->Model = clap.Model;
	this->HP = clap.HP;
	this->EP = clap.EP;
	this->MaxHP = clap.MaxHP;
	this->MaxEP = clap.MaxEP;
	this->rangedAttackDamage = clap.rangedAttackDamage;
	this->meleeAttackDamage = clap.meleeAttackDamage;
	this->Lvl = clap.Lvl;
	this->reductArmorDamage = clap.reductArmorDamage;
	return (*this);
}

ClapTrap::ClapTrap() {
	Name = "_";
	Model = "";
	std::cout << "Create new ClapTrap" << getName() << "!" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 100;
	MaxEP = 100;
	Lvl = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	reductArmorDamage = 5;
}

ClapTrap::~ClapTrap() {
	this->setModel("");
	std::cout << "Destroy ClapTrap" << getName() << "!" << std::endl;
}

std::string	ClapTrap::damage(std::string target, std::string mode, unsigned int amount) {
	std::string	s;
	if (mode == "range") {
		s.append(" range attack [\033[1;33m");
		s.append(target);
		s.append("\033[0m] ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "melee") {
		s.append(" melee attack [\033[1;33m");
		s.append(target);
		s.append("\033[0m] ( [\033[1;33m");
		s.append(target);
		s.append("\033[0m] \033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m damage )");
	}
	if (mode == "take") {
		s.append(" takes [\033[1;31m");
		s.append(std::to_string(amount));
		s.append("\033[0m] damage.");
	}
	return (s);
}

std::string	ClapTrap::reparo(unsigned int amount) {
	std::string	s;
	s.append(" rastore [\033[1;32m");
	s.append(std::to_string(amount));
	s.append("\033[0m] points!");
	return (s);
}

std::string	ClapTrap::notEnergy() {
	std::string	s;
	s.append(" not energy.");
	return (s);
}

std::string	ClapTrap::destroy(int n) {
	std::string	s;
	if (n == 1) {
		s.append(" dye!");
	}
	if (n == 2) {
		s.append(" dead!");
	}
	return (s);
}

void	ClapTrap::rangedAttack(std::string const &target) {
	std::cout << getName() << damage(target, "range", rangedAttackDamage) << std::endl;
}

void	ClapTrap::meleeAttack(std::string const &target) {
	std::cout << getName() << damage(target, "melee", meleeAttackDamage) << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	amount -= reductArmorDamage;
	if (HP == 0) {
		std::cout << getName() << destroy(2) << std::endl;
	}
	else {
		if (HP < amount)
			HP = 0;
		else
			HP -= amount;
		std::cout << getName() << damage("", "take", amount) << std::endl;
		std::cout << "\t";
		std::cout << getName() << " \033[1;35m" << HP << "\033[0m" << " hp left" << std::endl;
		if (HP == 0) {
			std::cout << "\t\t";
			std::cout << getName() << destroy(1) << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (amount > EP) {
		std::cout << getName() << notEnergy() << std::endl;
	}
	else {
		if (HP + amount > MaxHP)
			amount = MaxHP - HP;
		std::cout << getName() << reparo(amount) << std::endl;
		HP += amount;
		EP -= amount;
	}
	std::cout << "\t";
	std::cout << getName() << " has \033[1;35m" << HP << "\033[0m hp and \033[1;35m" << EP << "\033[0m ep"  << std::endl;
}
