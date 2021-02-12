/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:46:10 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/24 15:08:07 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
# include <exception>

typedef std::vector<int>::iterator iter;

class Span {
private:
	unsigned int		n;
	std::vector<int>	vec;
public:
	Span();
	Span(unsigned int);
	Span(const Span &other);
	virtual ~Span();
	Span		&operator=(const Span &other);
	void		addNumber(int);
	void		addNumber(int, int);
	void		addNumber(iter, iter);
	int			shortestSpan();
	int			longestSpan();
	
	class SpanException : public std::exception {
	private:
		std::string	error;
	public:
		SpanException();
		SpanException(std::string);
		SpanException(const SpanException &other);
		virtual ~SpanException() throw ();
		SpanException	&operator=(const SpanException &other);
		virtual	const char *what() const throw ();
	};
};

#endif
