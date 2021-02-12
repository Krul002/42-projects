/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:47:47 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 21:11:41 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int		main() {
	std::string name;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Lower";
		Bureaucrat n(name, 150);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Higher";
		Bureaucrat n(name, 1);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Lower than necessary";
		Bureaucrat n(name, 151);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Higher than necessary";
		Bureaucrat n(name, 0);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Medium";
		Bureaucrat n(name, 75);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Lower-1";
		Bureaucrat n(name, 150);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.decrement();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Higher+1";
		Bureaucrat n(name, 1);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.increment();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;try
	{
		name = "Higher-1";
		Bureaucrat n(name, 1);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.decrement();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;try
	{
		name = "Lower+1";
		Bureaucrat n(name, 150);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.increment();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Medium-10";
		Bureaucrat n(name, 75);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		n.decrement();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	try
	{
		name = "Medium+10";
		Bureaucrat n(name, 75);
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		std::cout << "\033[1;32mYES:" << n << "\033[0m" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "\033[1;31mNO:" << name << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	return (0);
}