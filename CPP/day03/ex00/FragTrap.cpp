/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:18:25 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:44:24 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

std::ostream	&FragTrap::nameCout(void) {
	return (std::cout << "FR4G-TP<\033[1;34m" << Name << "\033[0m> ");
}

const std::string	FragTrap::damage(unsigned int amount) {
	std::string	s;
	s.append("\033[1;31m");
	s.append(std::to_string(amount));
	s.append("\033[0m");
	return (s);
}
const std::string		FragTrap::target(std::string const & target) {
	std::string	s;
	s.append("[\033[1;33m");
	s.append(target);
	s.append("\033[0m]");
	return (s);
}

FragTrap::FragTrap() {
	Name = "_";
	nameCout() << "created" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 100;
	MaxEP = 1000;
	Lvl = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	reductArmorDamage = 5;
}

FragTrap::FragTrap(std::string name) {
	Name = name;
	nameCout() << "created" << std::endl;
	HP = 100;
	MaxHP = 100;
	EP = 100;
	MaxEP = 1000;
	Lvl = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	reductArmorDamage = 5;
}

FragTrap::FragTrap(const FragTrap &frag) {
	std::cout << "Copy construct FragTrap " << frag.Name << std::endl;
	*this = frag;
}

FragTrap			&FragTrap::operator=(const FragTrap &frag) {
	std::cout << "Assignation operator called" << std::endl;
	this->Name = frag.Name;
	this->HP = frag.HP;
	this->EP = frag.EP;
	this->MaxHP = frag.MaxHP;
	this->MaxEP = frag.MaxEP;
	this->rangedAttackDamage = frag.rangedAttackDamage;
	this->meleeAttackDamage = frag.meleeAttackDamage;
	this->Lvl = frag.Lvl;
	this->reductArmorDamage = frag.reductArmorDamage;
	return (*this);
}


FragTrap::~FragTrap() {
	nameCout() << "destroyed" << std::endl;
}

void	FragTrap::rangedAttack(std::string const &target) {
	nameCout() << "throws a snowball into " << this->target(target) << "!";
	std::cout << " ( " << target << " takes " << this->damage(rangedAttackDamage) << " damage )" << std::endl;
}

void	FragTrap::meleeAttack(std::string const &target) {
	nameCout() << "hugs " << this->target(target) << " in his arms!";
	std::cout << " ( " << target << " takes " << this->damage(meleeAttackDamage) << " damage )" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	amount -= reductArmorDamage;
	if (HP == 0) {
		nameCout() << "already destroyed, stop mocking the corpse!" << std::endl;
	}
	else {
		if (HP < amount)
			HP = 0;
		else
			HP -= amount;
		nameCout() << "hit by a meteorite, he takes " << this->damage(amount) << " damage. ";
		if (amount < MaxHP / 5) {
			std::cout << "Apparently the meteorite was small-_-" << std::endl;
		}
		else if (amount > MaxHP) {
			std::cout << "Apparently the meteorite was very large-_-" << std::endl;
		}
		else {
			std::cout << "Ordinary meteorite-_-" << std::endl;
		}
		std::cout << "\t";
		nameCout() << "\033[1;35m" << HP << "\033[0m" << " hp left" << std::endl;
		if (HP == 0) {
			std::cout << "\t\t";
			nameCout() << "lost the remnants of his brain" << std::endl;
		}
	}
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (amount > EP) {
		nameCout() << "does not have enough money for this procedure" << std::endl;
	}
	else {
		if (HP + amount > MaxHP)
			amount = MaxHP - HP;
		nameCout() << "drinks machine oil, his health is restored by " << this->damage(amount) << " points" << std::endl;
		HP += amount;
		EP -= amount;
	}
	std::cout << "\t";
	nameCout() << "has \033[1;35m" << HP << "\033[0m hp and \033[1;35m" << EP << "\033[0m ep"  << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	int		random = rand() % 6;
	std::string	poke[] = {"Jolteon", "Swampert", "Torkoal", "Flygon", "Gardevoir", "Doublade"};
	std::string move[] = {"Thunderbolt", "Muddy Water", "Overheat", "Dragon Claw", "Psychic", "Night Slash"};
	unsigned int	damage[] = {90, 90, 130, 80, 90, 70};
	if (EP >= 25) {
		EP -= 25;
		nameCout() << "\"Go! " << this->target(poke[random]) << "!" << std::endl << "\t" << this->target(poke[random]) << " used " << this->target(move[random]) << std::endl;
		std::cout << "\t" << this->target(target) << " takes " << this->damage(damage[random]) << " damage" << std::endl << "\t";
	}
	else {
		nameCout() << "does not have enough money for this procedure" << std::endl;
	}
	std::cout << "\t";
	nameCout() << "has \033[1;35m" << HP << "\033[0m hp and \033[1;35m" << EP << "\033[0m ep"  << std::endl;
}
