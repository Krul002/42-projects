/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:20:16 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 13:45:43 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
	const std::string	name;
	const int			gradeToSignature;
	const int			gradeToExeption;
	bool		signature;
	int			liarTrap(int grade);
public:
	Form();
	Form(std::string name, int gradeToSignature, int gradeToExeption);
	Form(const Form &form);
	~Form();
	Form		&operator=(const Form &form);

	void			beSigned(Bureaucrat &bur);
	std::string		getName() const;
	bool			getSignature() const;
	int				getGradeToSignature() const;
	int				getGradeToExeption() const;

	class GradeTooHighException : public std::exception {
	public:
		GradeTooHighException();
		GradeTooHighException(const GradeTooHighException &toHight);
		virtual ~GradeTooHighException() throw ();
		GradeTooHighException		&operator=(const GradeTooHighException &toHight);
		virtual	const char *what() const throw ();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		GradeTooLowException();
		GradeTooLowException(const GradeTooLowException &toLow);
		virtual ~GradeTooLowException() throw ();
		GradeTooLowException		&operator=(const GradeTooLowException &toLow);
		virtual	const char *what() const throw ();
	};
};

std::ostream		&operator<<(std::ostream &fd, const Form &form);

#endif