/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 07:21:47 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 09:51:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

/*======================================================================*/
/*===============>   Scalar::Construcs and descrutor   <================*/
/*======================================================================*/

Scalar::Scalar() : num(0), precision(1), s("0") {
}

Scalar::Scalar(std::string &s) : num(0), precision(1), s(s) {
}

Scalar::Scalar(const Scalar &sc) : s(sc.s) {
	*this = sc;
}

Scalar	&Scalar::operator=(const Scalar &sc) {
	this->s = sc.s;
	this->num = sc.num;
	this->precision = sc.precision;
	return (*this);
}

Scalar::~Scalar() {}

/*======================================================================*/
/*======================>   Scalar::Outputs   <=========================*/
/*======================================================================*/

void	Scalar::toDouble() {
	std::cout << "double: " << std::fixed << std::setprecision(this->precision) << this->num << std::endl;
}

void	Scalar::toFloat() {
	float	f;

	f = static_cast<float>(this->num);
	// if (std::isnan(this->num))
	// 	f = nanf("");
	std::cout << "float: " << std::fixed << std::setprecision(this->precision) << f << "f" << std::endl;
}

void	Scalar::toInt() {
	int		i = 0;

	try {
		std::cout << "int: ";
		if (std::isnan(this->num) || this->num < static_cast<double>(INT_MIN) || this->num > static_cast<double>(INT_MAX))
			throw Scalar::ScalarException("imposible", "");
		i = static_cast<int>(this->num);
		std::cout << i << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Scalar::toChar() {
	char	c;

	try {
		std::cout << "char: ";
		if (std::isnan(this->num) || this->num < static_cast<double>(CHAR_MIN) || this->num > static_cast<double>(CHAR_MAX))
			throw Scalar::ScalarException("imposible", "");
		c = static_cast<char>(this->num);
		if (!isprint(c))
			throw Scalar::ScalarException("Non displayable", "");
		std::cout << "\'" << c << "\'" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void	Scalar::getNumbers(std::string s) {
	this->s = s;
	this->num = 0;
	this->precision = 1;
	try
	{
		split();
		parse();
		toChar();
		toInt();
		toFloat();
		toDouble();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/*======================================================================*/
/*========================>   Scalar::Parser   <========================*/
/*======================================================================*/

bool	Scalar::length(size_t num1, size_t num2) {
	if (this->s.length() >= num1 && this->s.length() <= num2)
		return (true);
	return (false);
}

void	Scalar::split() {
	std::string skip = "\t\v\f\r\n ";
	size_t	start = this->s.find_first_not_of(skip);
	if (start == std::string::npos)
		start = this->s.length();
	size_t	end = this->s.find_last_not_of(skip, this->s.length()) + 1;
	this->s = this->s.substr(start, end - start);
}

bool	Scalar::nan(double &sign) {
	if (this->s.find("nan") != std::string::npos) {
		if (this->length(3, 3) && sign != 0)
			throw Scalar::ScalarException("sign nan");
		else if (this->length(3, 3) || (this->length(4, 4) && s[3] == 'f'))
			this->num = NAN;
		else
			throw Scalar::ScalarException("not number");
		return true;
	}
	return false;
}

bool	Scalar::inf(double &sign) {
	if (this->s.find("inf") != std::string::npos) {
		if (this->length(3, 3) || (this->length(4, 4) && s[3] == 'f'))
			this->num = INFINITY * sign;
		else
			throw Scalar::ScalarException("not number");
		return true;
	}
	return false;
}

bool	Scalar::sign(double &sign) {
	int		i = 0;
	for (i = 0; s[i] == '+' || s[i] == '-'; i++) {
		if (sign != 0)
			throw Scalar::ScalarException("multiple sign");
		if (this->s[i] == '+')
			sign = 1;
		if (this->s[i] == '-')
			sign = -1;
	}
	this->s = this->s.substr(i, s.length() - i);
	return true;
}

void	Scalar::number(double &sign) {
	std::size_t	i = 0;
	bool		point = false;

	for (i = 0; isdigit(this->s[i]); i++)
		this->num = this->num * 10 + this->s[i] - '0';
	i = (s[i] == '.' && (point = true)) ? i + 1 : i;
	this->precision = i;
	for (double n = 10; isdigit(s[i]); i++, n *= 10)
		this->num += (this->s[i] - '0') / n;
	this->precision = i - this->precision;
	if (this->precision <= 0)
		this->precision = 1;
	i = (s[i] == 'f' && !this->s[i + 1] && point) ? i + 1 : i;
	if (i != this->s.length())
		throw Scalar::ScalarException("not number");
	this->num *= sign;
}

double	Scalar::parse() {
	double			sign = 0;
	char			c;

	if (this->s.length() == 0)
		throw Scalar::ScalarException();
	if (this->length(1, 1)) {
		c = static_cast<char>(s[0]);
		if (isdigit(c))
			c -= '0';
		this->num = static_cast<double>(c);
		return this->num;
	}
	this->sign(sign);
	if (this->nan(sign) == true)
		return this->num;
	sign = !sign ? 1 : sign;
	if (this->inf(sign) == true)
		return this->num;
	this->number(sign);
	return this->num;
}

/*======================================================================*/
/*=====================>   Scalar::ScalarException	<===================*/
/*======================================================================*/

Scalar::ScalarException::ScalarException() : std::exception(), error("ScalarException error: empty") {
}

Scalar::ScalarException::ScalarException(std::string msg) : std::exception(), error("ScalarException error: " + msg) {
}

Scalar::ScalarException::ScalarException(std::string msg, std::string error) : std::exception(), error(error + msg) {
}

Scalar::ScalarException::~ScalarException() throw () {
}

Scalar::ScalarException &Scalar::ScalarException::operator=(const ScalarException &se) {
	this->error = se.error;
	return (*this);
}

const char	*Scalar::ScalarException::what() const throw () {
	return this->error.c_str();
}

void	Scalar::ScalarException::outException(std::string error) {
	this->error = error;
}
