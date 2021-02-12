/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:36:18 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 18:08:04 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string.h>
# include <exception>

class Form;

class Bureaucrat {
private:
	const std::string	name;
	int			grade;
	int			liarTrap(int grade);
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bur);
	~Bureaucrat();
	Bureaucrat		&operator=(const Bureaucrat &bur);

	void			signForm(Form &form);
	void			executeForm (Form const &form);
	std::string		getName() const;
	int				getGrade() const;
	int				increment();
	int				decrement();

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

std::ostream		&operator<<(std::ostream &fd, const Bureaucrat &bur);

#endif

