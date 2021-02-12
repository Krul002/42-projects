/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:53:39 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 22:54:15 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/*==============================================================================*/
/*class Intern*/
/*==============================================================================*/

Intern::Intern() {
}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern::~Intern() {
}

Intern		&Intern::operator=(const Intern &intern) {
	(void)intern;
	return (*this);
}

Form		*Intern::makeForm(std::string name, std::string target) {
	std::string	names[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	Form	*(Intern::*funk[3])(std::string target) = {&Intern::newPresidentialPardon, &Intern::newRobotomyRequest, &Intern::newShrubberyCreation};
	for (int i = 0; i < 3; i++) {
		if (name == names[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*funk[i])(target));
		}
	}
	throw Intern::NotFoundFormException(name);
}

Form	*Intern::newPresidentialPardon(std::string target) {
	return (new PresidentialPardonForm(target));
}

Form	*Intern::newRobotomyRequest(std::string target) {
	return (new RobotomyRequestForm(target));
}

Form	*Intern::newShrubberyCreation(std::string target) {
	return (new ShrubberyCreationForm(target));
}

/*==============================================================================*/
/*class Intern::NotFoundFormException*/
/*==============================================================================*/

Intern::NotFoundFormException::NotFoundFormException() : std::exception(), error("Not found form") {
}

Intern::NotFoundFormException::NotFoundFormException(std::string name) : std::exception(), error("Not found " + name + " form") {
}

Intern::NotFoundFormException::NotFoundFormException(const NotFoundFormException &notFound) : error(notFound.error) {
	*this = notFound;
}

Intern::NotFoundFormException::~NotFoundFormException() throw() {
}

Intern::NotFoundFormException		&Intern::NotFoundFormException::operator=(const NotFoundFormException &notFound) {
	(void)notFound;
	return (*this);
}

const char *Intern::NotFoundFormException::what() const throw () {
	return (this->error.c_str());
}
