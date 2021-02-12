/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 08:15:09 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/24 06:20:15 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>

int     main() {
	std::cout << "====================================================================|============" << std::endl;
	std::cout << "Vectors tests: " << std::endl;
	{
		std::vector<int>    vec;
		int                 n = 10;
		vec.push_back(n);
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 20;
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		vec.push_back(n);
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = -57;
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		vec.push_back(n);
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 2000000000;
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		vec.push_back(n);
		if (easyfind(vec, n) != vec.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
	}
	std::cout << "====================================================================|============" << std::endl;
	std::cout << "Lists tests: " << std::endl;
	{
		std::list<int>    l;
		int                 n = 10;
		l.push_back(n);
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 20;
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		l.push_back(n);
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = -57;
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		l.push_back(n);
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 2000000000;
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		l.push_back(n);
		if (easyfind(l, n) != l.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
	}
	std::cout << "====================================================================|============" << std::endl;
	std::cout << "Set tests: " << std::endl;
	{
		std::set<int>    s;
		int                 n = 10;
		s.insert(n);
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 20;
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		s.insert(n);
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = -57;
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		s.insert(n);
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		n = 2000000000;
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
		s.insert(n);
		if (easyfind(s, n) != s.end())
			std::cout << n << "!...Yes, this number is present in the container!" << std::endl;
		else
			std::cout << n << "!...No, this number was not registered for the meeting(" << std::endl;
	}
	std::cout << "====================================================================|============" << std::endl;
	return 0;
}