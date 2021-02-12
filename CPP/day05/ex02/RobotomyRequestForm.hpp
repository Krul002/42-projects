/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:09:32 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 18:26:43 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cerrno>
# include <fstream>
# include <cstring>
# include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &form);
	~RobotomyRequestForm();
	RobotomyRequestForm		&operator=(const RobotomyRequestForm &form);

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