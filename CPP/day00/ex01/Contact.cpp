/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:50:36 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 08:40:11 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	index = 0;
	f_name = "";
	l_name = "";
	nick = "";
	login = "";
	pos_addr = "";
	email = "";
	phone_num = "";
	birthday = "";
	f_meal = "";
	u_color = "";
	dark_secret = "";
}

int			Contact::setData(std::string s, std::string *s1) {
	std::cout << s;
	std::getline(std::cin, *s1);
	if (std::cin.eof()) {
		std::cout << "\nADD - new contact, SEARCH - find contact, EXIT - stop program" << std::endl << "You command please: " << "EXIT" << std::endl;
		return (1);
	}
	return (0);
}

void		Contact::getData(std::string s, std::string s1) {
	std::cout << s << "\""<< s1 << "\"" << std::endl;
}

int			Contact::setContact(int i) {
	index = i;
	if (setData("First name:\t\t", &f_name))
		return (1);
	if (setData("Last name:\t\t", &l_name))
		return (1);
	if (setData("Nickname:\t\t", &nick))
		return (1);
	if (setData("Login:\t\t\t", &login))
		return (1);
	if (setData("Postal address:\t\t", &pos_addr))
		return (1);
	if (setData("Email address:\t\t", &email))
		return (1);
	if (setData("Phone number:\t\t", &phone_num))
		return (1);
	if (setData("Birthday date:\t\t", &birthday))
		return (1);
	if (setData("Favorite meal:\t\t", &f_meal))
		return (1);
	if (setData("Underwear color:\t", &u_color))
		return (1);
	if (setData("Darkest secret:\t\t", &dark_secret))
		return (1);
	return (0);
}

void		Contact::getContact() {
	getData("First name:\t\t", f_name);
	getData("Last name:\t\t", l_name);
	getData("Nickname:\t\t", nick);
	getData("Login:\t\t\t", login);
	getData("Postal address:\t\t", pos_addr);
	getData("Email address:\t\t", email);
	getData("Phone number:\t\t", phone_num);
	getData("Birthday date:\t\t", birthday);
	getData("Favorite meal:\t\t", f_meal);
	getData("Underwear color:\t", u_color);
	getData("Darkest secret:\t\t", dark_secret);
}

void		Contact::getFormatData(std::string s) {
	int		len;
	std::cout << "|";
	len = 10 - s.length();
	len -= len / 2;
	while (len-- > 0)
		std::cout << " ";
	len = s.length();
	for (int i = 0; i < 10 && len-- > 0; i++) {
		if (i == 9 && len != 0)
			std::cout << ".";
		else
			std::cout << s[i];
	}
	len = (10 - s.length()) / 2;
	while (len-- > 0)
		std::cout << " ";
}

void		Contact::getFormatContact() {
	std::cout << " |         " << index;
	getFormatData(f_name);
	getFormatData(l_name);
	getFormatData(nick);
	std::cout << "| " << std::endl;
}
