/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:55:34 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:47:52 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {
	this->name = "_";
	this->title = "_";
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(std::string	name, std::string	title) {
	this->name = name;
	this->title = title;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &sorcerer) {
	std::cout << "Copy Sorcerer " << sorcerer.name << "!" << std::endl;
	*this = sorcerer;
	std::cout << this->name << ", " << this->title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer() {
	std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &sorcerer) {
	std::cout << "Assignation operator called" << std::endl;
	this->name = sorcerer.name;
	this->title = sorcerer.title;
	return (*this);
}

void		Sorcerer::polymorph(Victim const &vic) const {
	vic.getPolymorphed();
}

std::string		Sorcerer::getName() const {
	return (this->name);
}

std::string		Sorcerer::getTitle() const {
	return (this->title);
}

std::ostream	&operator<<(std::ostream &fd, const Sorcerer &sorcerer) {
	return (fd << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl);
}
