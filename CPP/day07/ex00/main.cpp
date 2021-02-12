/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:45:36 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 10:55:32 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <climits>
#include <cmath>
#include <string>

int main( void ) {
	std::cout << "=============================================================================|====" << std::endl;
	std::cout << "Standart tests:" << std::endl;
	{
		int	a = 2;
		int	b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << "=============================================================================|====" << std::endl;
	std::cout << "My Tests:" << std::endl << std::endl;
	{
		std::cout << "INT" << std::endl;
		int		a = 2;
		int		b = 5;
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		a = INT_MAX;
		b = INT_MIN;
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;
	}
	{
		std::cout << "FLOAT" << std::endl;
		float		a = 100.99f;
		float		b = 100.98f;
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		a = INFINITY;
		b = -INFINITY;
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;
	}
	{
		std::cout << "STRING" << std::endl;
		std::string		a = "no";
		std::string		b = "ni";
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
		a = "0000000000000";
		b = "0000000000001";
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << "; b = " << b << ";" << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl << std::endl;
	}
	std::cout << "=============================================================================|====" << std::endl;
	return 0;
}