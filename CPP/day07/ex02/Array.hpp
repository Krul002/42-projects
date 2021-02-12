/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:41:52 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/23 08:30:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array {
private:
	size_t	_size;
	T		*arr;
public:
	Array();
	Array(int);
	Array(const Array &);
	virtual ~Array();
	Array	&operator=(const Array &);
	T		&operator[](int);
	size_t	size() const;
	class	NotElementException : public std::exception {
	private:
		std::string	error;
	public:
		NotElementException();
		NotElementException(int, size_t);
		NotElementException(const NotElementException &);
		virtual	~NotElementException() throw ();
		void	messageError(int, size_t);
		NotElementException	&operator=(const NotElementException &);
		virtual const char* what() const throw ();
	};
};

# include "Array.ipp"

#endif
