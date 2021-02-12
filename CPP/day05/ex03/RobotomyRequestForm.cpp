/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:09:12 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 21:59:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*==============================================================================*/
/*class RobotomyRequestForm*/
/*==============================================================================*/

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request", "_", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) {
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm		&RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
	Form::operator=(form);
	return (*this);
}

void			RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	int	random = rand() % 2;

	std::cout << "" << "bzzz...bzzz...bzzz...bzzz..." << std::endl;
	if (random == 0)
		throw RobotomyRequestForm::ExecuteException();
	std::cout << this->getTarget() << " has been robotomized" << std::endl;
	
}

/*==============================================================================*/
/*class RobotomyRequestForm::ExecuteException*/
/*==============================================================================*/

RobotomyRequestForm::ExecuteException::ExecuteException() : std::exception() {
}

RobotomyRequestForm::ExecuteException::ExecuteException(const ExecuteException &execute) {
	*this = execute;
}

RobotomyRequestForm::ExecuteException::~ExecuteException() throw() {
}

RobotomyRequestForm::ExecuteException		&RobotomyRequestForm::ExecuteException::operator=(const ExecuteException &execute) {
	(void)execute;
	return (*this);
}

const char *RobotomyRequestForm::ExecuteException::what() const throw () {
	return ("robotization failed");
}
