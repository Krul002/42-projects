/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:37:55 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 18:10:36 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <cerrno>
# include <fstream>
# include <cstring>
# include "Form.hpp"

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &form);
	~ShrubberyCreationForm();
	ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &form);

	virtual void				execute(Bureaucrat const & executor) const;

	class ExecuteException : public std::exception {
	public:
		ExecuteException();
		ExecuteException(const ExecuteException &execute);
		virtual ~ExecuteException() throw ();
		ExecuteException		&operator=(const ExecuteException &execute);
		virtual	const char *what() const throw ();
	};
};

#endif
