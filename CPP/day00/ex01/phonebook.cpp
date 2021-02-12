/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:57:01 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 08:39:01 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int		search(Contact *cont, int i) {
	int		n;
	std::string s;

	n = 0;
	std::cout << "-|----------|----------|----------|----------|-" << std::endl;
	std::cout << " |   INDEX  |FIRST NAME| LAST NAME| NICKNAME | " << std::endl;
	std::cout << "-|----------|----------|----------|----------|-" << std::endl;
	while (n < i)
	{
		cont[n].getFormatContact();
		std::cout << "-|----------|----------|----------|----------|-" << std::endl;
		n++;
	}
	if (i > 0) {
		std::cout << "Enter contact index: ";
		std::getline(std::cin, s);
		if (std::cin.eof()) {
			std::cout << "\nADD - new contact, SEARCH - find contact, EXIT - stop program" << std::endl << "You command please: " << "EXIT" << std::endl;
			return (1);
		}
		n = s[0] - '0';
		if (s.length() > 1 || isalnum(s[0]) == 0 || n >= i)
			std::cout << "Wrong number!" << std::endl;
		else
			cont[n].getContact();
	}
	return (0);
}

int		main() {
	Contact		test[8];
	int			i;
	std::string	comand;

	i = 0;
	while (1) {
		std::cout << "ADD - new contact, SEARCH - find contact, EXIT - stop program" << std::endl << "You command please: ";
		std::getline(std::cin, comand);
		if (comand == "ADD") {
			if (i < 8) {
				if (test[i].setContact(i) == 1)
					return (0);
				i++;
			}
			else
				std::cout << "There is no room in the phone book!" << std::endl;
		}
		else if (comand == "SEARCH") {
			if (search(test, i) == 1)
				return (0);
		}
		else if (comand == "EXIT") {
			break ;
		}
		else {
			if (std::cin.eof()) {
				std::cout << "EXIT" << std::endl;
				return (0);
			}
			std::cout << "Bad comand." << std::endl;
		}
	}
	return (0);
}
