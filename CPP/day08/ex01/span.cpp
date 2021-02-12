/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:07:50 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/24 15:08:23 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int n) : n(n) {}

Span::Span(const Span &other) : n(other.n), vec(other.vec) {
	*this = other;
}

Span::~Span() {}

Span	&Span::operator=(const Span &other) {
	this->n = other.n;
	this->vec = other.vec;
	return *this;
}

void	Span::addNumber(int num) {
	if (this->vec.size() >= static_cast<size_t>(this->n))
		throw Span::SpanException();
	this->vec.push_back(num);
}

void	Span::addNumber(int from, int to) {
	if (from > to)
		throw Span::SpanException("Impossible sequence!");
	if (this->vec.size() + static_cast<size_t>(to - from) >= static_cast<size_t>(this->n))
		throw Span::SpanException();
	for (int i = from; i <= to; i++)
		this->vec.push_back(i);
}

void	Span::addNumber(iter from, iter to) {
	if (from > to)
		throw Span::SpanException("Impossible sequence!");
	if (this->vec.size() + static_cast<size_t>(to - from) >= static_cast<size_t>(this->n))
		throw Span::SpanException();
	for (iter i = from; i != to; i++)
		this->vec.push_back(*i);
}

int		Span::shortestSpan() {
	std::vector<int>	cpy;
	int					res;
	iter				it;

	if (this->vec.size() < 2)
		throw Span::SpanException("Not enough values!");
	cpy = this->vec;
	it = cpy.begin();
	res = *(it + 1) - *it;
	std::sort(cpy.begin(), cpy.end());
	for (it = cpy.begin() + 1; it != cpy.end() - 1; it++) {
		if (*(it + 1) - *it < res)
			res = *(it + 1) - *it;
	}
	return res;
}

int		Span::longestSpan() {
	std::vector<int>	cpy;

	if (this->vec.size() < 2)
		throw Span::SpanException("Not enough values!");
	cpy = this->vec;
	std::sort(cpy.begin(), cpy.end());
	return *(cpy.end() - 1) - *cpy.begin();
}

/*=================================================================================================================================*/
/*===================================================>   Span::SpanException   <===================================================*/
/*=================================================================================================================================*/

Span::SpanException::SpanException() : std::exception(), error("SpanException error: Not enough storage!") {}

Span::SpanException::SpanException(std::string error) : std::exception(), error("SpanException error: " + error) {}

Span::SpanException::SpanException(const SpanException &other) : std::exception(), error(other.error) {
	*this = other;
}

Span::SpanException::~SpanException() throw () {}

Span::SpanException &Span::SpanException::operator=(const SpanException &other) {
	this->error = other.error;
	return *this;
}

const char *Span::SpanException::what() const throw () {
	return this->error.c_str();
}
