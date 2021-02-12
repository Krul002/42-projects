/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:44:07 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 08:33:30 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string.h>

class	Contact {
private:
	int			index;
	std::string	f_name;
	std::string	l_name;
	std::string	nick;
	std::string	login;
	std::string	pos_addr;
	std::string	email;
	std::string	phone_num;
	std::string	birthday;
	std::string	f_meal;
	std::string	u_color;
	std::string	dark_secret;
public:
	Contact();
	int			setData(std::string s, std::string *s1);
	void		getData(std::string s, std::string s1);
	int			setContact(int i);
	void		getContact();
	void			getFormatData(std::string s);
	void		getFormatContact();
};

#endif
