/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:13:02 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 22:54:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern &intern);
	~Intern();
	Intern		&operator=(const Intern &intern);
	Form		*makeForm(std::string name, std::string target);
	Form		*newPresidentialPardon(std::string target);
	Form		*newRobotomyRequest(std::string target);
	Form		*newShrubberyCreation(std::string target);
	
	class NotFoundFormException : public std::exception {
	private:
		const std::string error;
	public:
		NotFoundFormException();
		NotFoundFormException(std::string name);
		NotFoundFormException(const NotFoundFormException &notFound);
		virtual ~NotFoundFormException() throw ();
		NotFoundFormException		&operator=(const NotFoundFormException &notFound);
		virtual	const char *what() const throw ();
	};
};

#endif