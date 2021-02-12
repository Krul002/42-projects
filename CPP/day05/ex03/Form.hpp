/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:20:16 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 21:15:35 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;

# include "Bureaucrat.hpp"

class Form {
private:
	const std::string	name;
	const std::string	target;
	const int			gradeToSignature;
	const int			gradeToExeption;
	bool		signature;
	int			liarTrap(int grade);
public:
	Form();
	Form(std::string name, std::string target, int gradeToSignature, int gradeToExeption);
	Form(const Form &form);
	virtual ~Form();
	Form		&operator=(const Form &form);

	void			beSigned(Bureaucrat &bur);
	virtual void	execute(Bureaucrat const & executor) const;
	std::string		getName() const;
	std::string		getTarget() const;
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
	
	class NotSignedExaption : public std::exception {
	public:
		NotSignedExaption();
		NotSignedExaption(const NotSignedExaption &toLow);
		virtual ~NotSignedExaption() throw ();
		NotSignedExaption		&operator=(const NotSignedExaption &toLow);
		virtual	const char *what() const throw ();
	};
};

std::ostream		&operator<<(std::ostream &fd, const Form &form);

#endif
