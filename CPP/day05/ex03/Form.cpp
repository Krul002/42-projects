/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:23:31 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 21:58:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*==============================================================================*/
/*class Form*/
/*==============================================================================*/

Form::Form() : name("_"), target("?"), gradeToSignature(1), gradeToExeption(1) {
	this->signature = false;
}

Form::Form(std::string name, std::string target, int gradeToSignature, int gradeToExeption) : name(name), target(target), gradeToSignature(liarTrap(gradeToSignature)), gradeToExeption(liarTrap(gradeToExeption)) {
	this->signature = false;
}

Form::Form(const Form &form) : name(form.name), target(form.target), gradeToSignature(form.gradeToExeption), gradeToExeption(form.gradeToExeption) {
	*this = form;
}

Form::~Form() {
}

Form		&Form::operator=(const Form &form) {
	this->signature = form.signature;
	return (*this);
}

int				Form::liarTrap(int grade) {
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return (grade);
}

void			Form::beSigned(Bureaucrat &bur) {
	if (bur.getGrade() > this->gradeToSignature)
		throw Form::GradeTooLowException();
	this->signature = true;
}

void			Form::execute(Bureaucrat const &executor) const {
	if (this->signature == false)
		throw Form::NotSignedExaption();
	if (executor.getGrade() > this->gradeToExeption)
		throw Form::GradeTooLowException();
}

std::string		Form::getName() const {
	return (this->name);
}

std::string		Form::getTarget() const {
	return (this->target);
}

bool			Form::getSignature() const {
	return (this->signature);
}

int				Form::getGradeToSignature() const {
	return (this->gradeToSignature);
}

int				Form::getGradeToExeption() const {
	return (this->gradeToExeption);
}

std::ostream		&operator<<(std::ostream &fd, const Form &form) {
	return (fd << form.getName() << (form.getSignature() == true ? ", " : ", not ") << "signed. To sign, a score is required: " << form.getGradeToSignature()
	 << ". To complete, a score is required: " << form.getGradeToExeption() << ".");
}

/*==============================================================================*/
/*class Form::GradeTooHighException*/
/*==============================================================================*/

Form::GradeTooHighException::GradeTooHighException() : std::exception() {
}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException &toHight) {
	*this = toHight;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {
}

Form::GradeTooHighException		&Form::GradeTooHighException::operator=(const GradeTooHighException &toHight) {
	(void)toHight;
	return (*this);
}

const char *Form::GradeTooHighException::what() const throw () {
	return ("TooHigh");
}

/*==============================================================================*/
/*class Form::GradeTooLowException*/
/*==============================================================================*/

Form::GradeTooLowException::GradeTooLowException() : std::exception() {
}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException &toLow) {
	*this = toLow;
}

Form::GradeTooLowException::~GradeTooLowException() throw() {
}

Form::GradeTooLowException		&Form::GradeTooLowException::operator=(const GradeTooLowException &toLow) {
	(void)toLow;
	return (*this);
}

const char *Form::GradeTooLowException::what() const throw () {
	return ("TooLow");
}

/*==============================================================================*/
/*class Form::NotSignedExaption*/
/*==============================================================================*/

Form::NotSignedExaption::NotSignedExaption() : std::exception() {
}

Form::NotSignedExaption::NotSignedExaption(const NotSignedExaption &notSigned) {
	*this = notSigned;
}

Form::NotSignedExaption::~NotSignedExaption() throw() {
}

Form::NotSignedExaption		&Form::NotSignedExaption::operator=(const NotSignedExaption &notSigned) {
	(void)notSigned;
	return (*this);
}

const char *Form::NotSignedExaption::what() const throw () {
	return ("Not Signed");
}
