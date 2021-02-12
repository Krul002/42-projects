/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 07:20:47 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 13:49:19 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <cmath>
# include <string>
# include <climits>
# include <iomanip>
# include <exception>

class	Scalar {
private:
	double		num;
	int			precision;
	std::string s;
	bool		length(size_t, size_t);
	bool		nan(double &);
	bool		inf(double &);
	bool		sign(double &);
	void		number(double &);
public:
	Scalar();
	Scalar(std::string &);
	Scalar(const Scalar &);
	~Scalar();
	Scalar	&operator=(const Scalar &);
	void	split();
	double	parse();
	void	getNumbers(std::string);
	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

	class	ScalarException : public std::exception {
	private:
		std::string	error;
	public:
		ScalarException();
		ScalarException(std::string);
		ScalarException(std::string msg, std::string);
		virtual ~ScalarException() throw ();
		ScalarException	&operator=(const ScalarException &);
		virtual const char* what() const throw ();
		void		outException(std::string);
	};

};

#endif
