/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:34:38 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 21:02:24 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*==============================================================================*/
/*class PresidentialPardonForm*/
/*==============================================================================*/

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon", "_", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) {
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm		&PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
	Form::operator=(form);
	return (*this);
}

void			PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	Form::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
