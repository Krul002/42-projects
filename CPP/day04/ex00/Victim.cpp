/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:54:36 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:47:27 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim() {
	this->name = "_";
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(std::string	name) {
	this->name = name;
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &victim) {
	std::cout << "Copy Victim " << victim.name << "!" << std::endl;
	*this = victim;
	std::cout << "Some random victim called " << this->name << " just appeared!" << std::endl;
}

Victim::~Victim() {
	std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

Victim	&Victim::operator=(const Victim &victim) {
	std::cout << "Assignation operator called" << std::endl;
	this->name = victim.name;
	return (*this);
}

void	Victim::getPolymorphed() const {
	std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

void	Victim::setName(std::string	name) {
	this->name = name;
}

std::string		Victim::getName() const {
	return (this->name);
}

std::ostream	&operator<<(std::ostream &fd, const Victim &victim) {
	return (fd << "I'm " << victim.getName() << " and I like otters!" << std::endl);
}
