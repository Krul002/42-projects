/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:59:11 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/05 22:04:01 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main() {
	std::string s = "HI THIS IS BRAIN";
	std::string *s1 = &s;
	std::string	&s2 = s;

	std::cout << "Pointer:\t\"" << *s1 << "\"" << std::endl;
	std::cout << "Reference:\t\"" << s2 << "\"" << std::endl;
}