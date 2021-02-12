/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:47:47 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/10 14:08:55 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main() {
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	{
		Bureaucrat	n("Nina", 10);
		Form		f("Document", 5, 5);

		std::cout << "\033[1;33m" << n << "\n\033[0m\033[1;35m" << f << "\033[0m" <<std::endl <<std::endl;
		std::cout << "\033[1;34m";
		n.signForm(f);
		std::cout << "\033[0m" <<std::endl;
		std::cout << "\033[1;33m" << n << "\n\033[0m\033[1;35m" << f << "\033[0m" <<std::endl <<std::endl;
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		n.increment();
		std::cout << "\033[1;33m" << n << "\n\033[0m\033[1;35m" << f << "\033[0m" <<std::endl <<std::endl;
		std::cout << "\033[1;34m";
		n.signForm(f);
		std::cout << "\033[0m" <<std::endl;
		std::cout << "\033[1;33m" << n << "\n\033[0m\033[1;35m" << f << "\033[0m" <<std::endl <<std::endl;
		std::cout << "\033[1;34m";
		n.signForm(f);
		std::cout << "\033[0m" <<std::endl;
		std::cout << "\033[1;33m" << n << "\n\033[0m\033[1;35m" << f << "\033[0m" <<std::endl <<std::endl;
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	{
		std::cout << "\033[1;33mDocument:150:5" << std::endl;
		try
		{
			Form		f("Document", 151, 5);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:0:5" << std::endl;
		try
		{
			Form		f("Document", 0, 5);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:15:500" << std::endl;
		try
		{
			Form		f("Document", 15, 500);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:15:-1" << std::endl;
		try
		{
			Form		f("Document", 15, -1);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:151:500" << std::endl;
		try
		{
			Form		f("Document", 151, 500);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:0:-5" << std::endl;
		try
		{
			Form		f("Document", 0, -5);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:600:-5" << std::endl;
		try
		{
			Form		f("Document", 600, -5);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:0:900" << std::endl;
		try
		{
			Form		f("Document", 0, 900);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
		std::cout << "\033[1;33mDocument:150:1" << std::endl;
		try
		{
			Form		f("Document", 150, 1);
			std::cout << "\033[1;32mYES: \033[1;35m" << f << "\033[0m" <<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "\033[1;31mNO: Document: " << e.what() << "\033[0m" << std::endl;
		}
	}
	std::cout << "-----------------------------------------------------------------------------------------------------------------------|----" << std::endl;
	return (0);
}