/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:35:54 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 22:00:03 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*==============================================================================*/
/*class ShrubberyCreationForm*/
/*==============================================================================*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation", "_", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", target, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) {
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm		&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	Form::operator=(form);
	return (*this);
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	std::ofstream	fout;

	fout.open(this->getTarget() + "_shrubbery", std::ios::trunc | std::ios::out);
	if (fout.is_open() == false)
		throw ShrubberyCreationForm::ExecuteException();
	fout << "       _-_" << std::endl;
	fout << "    /~~   ~~\\" << std::endl;
	fout << " /~~         ~~\\" << std::endl;
	fout << "{               }" << std::endl;
	fout << " \\  _-     -_  /" << std::endl;
	fout << "   ~  \\\\ //  ~" << std::endl;
	fout << "_- -   | | _- _" << std::endl;
	fout << "  _ -  | |   -_" << std::endl;
	fout << "      // \\\\" << std::endl;
	fout.close();
}

/*==============================================================================*/
/*class ShrubberyCreationForm::ExecuteException*/
/*==============================================================================*/

ShrubberyCreationForm::ExecuteException::ExecuteException() : std::exception() {
}

ShrubberyCreationForm::ExecuteException::ExecuteException(const ExecuteException &execute) {
	*this = execute;
}

ShrubberyCreationForm::ExecuteException::~ExecuteException() throw() {
}

ShrubberyCreationForm::ExecuteException		&ShrubberyCreationForm::ExecuteException::operator=(const ExecuteException &execute) {
	(void)execute;
	return (*this);
}

const char *ShrubberyCreationForm::ExecuteException::what() const throw () {
	return (std::strerror(errno));
}
