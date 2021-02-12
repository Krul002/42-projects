/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 21:12:28 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 22:01:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*==============================================================================*/
/*class Bureaucrat*/
/*==============================================================================*/

Bureaucrat::Bureaucrat() : name("_") {
	this->grade = 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
	this->grade = liarTrap(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name) {
	*this = bur;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat		&Bureaucrat::operator=(const Bureaucrat &bur) {
	this->grade = liarTrap(bur.grade);
	return (*this);
}

int				Bureaucrat::liarTrap(int grade) {
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return (grade);
}

std::string		Bureaucrat::getName() const {
	return (this->name);
}

int				Bureaucrat::getGrade() const {
	return (this->grade);
}

int				Bureaucrat::increment() {
	return (this->grade = liarTrap(this->grade - 1));
}

int				Bureaucrat::decrement() {
	return (this->grade = liarTrap(this->grade + 1));
}

std::ostream		&operator<<(std::ostream &fd, const Bureaucrat &bur) {
	return (fd << bur.getName() << ", bureaucrat grade " << bur.getGrade());
}

/*==============================================================================*/
/*class Bureaucrat::GradeTooHighException*/
/*==============================================================================*/

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException &toHight) {
	*this = toHight;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

Bureaucrat::GradeTooHighException		&Bureaucrat::GradeTooHighException::operator=(const GradeTooHighException &toHight) {
	(void)toHight;
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw () {
	return ("TooHigh");
}

/*==============================================================================*/
/*class Bureaucrat::GradeTooLowException*/
/*==============================================================================*/

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception() {
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException &toLow) {
	*this = toLow;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

Bureaucrat::GradeTooLowException		&Bureaucrat::GradeTooLowException::operator=(const GradeTooLowException &toLow) {
	(void)toLow;
	return (*this);
}

const char *Bureaucrat::GradeTooLowException::what() const throw () {
	return ("TooLow");
}
