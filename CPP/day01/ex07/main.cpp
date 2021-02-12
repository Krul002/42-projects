/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:06:40 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 01:07:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int		main(int size, char **args) {
	errno = 0;
	if (size != 4) {
		if (size < 4)
			std::cerr << "\033[1;31mToo few arguments! ";
		if (size > 4)
			std::cerr << "\033[1;31mToo many arguments! ";
		std::cerr << "Should be: \"file\" \"str1\" \"str2\".\033[0m" << std::endl;
		return (1);
	}
	std::string	name(args[0]);
	std::string	fileName(args[1]);
	std::string	str1(args[2]);
	std::string	str2(args[3]);
	if (name.empty() == true || fileName.empty() == true || str1.empty() == true || str2.empty() == true) {
		std::cerr << "Empty argument!" << std::endl;
		return (1);
	}
	Replace	replace;
	if (replace.readFile(fileName) != 0 || replace.replaceString(str1, str2) != 0 || replace.writeFile(fileName + ".replace") != 0) {
		std::cerr << name << ": " << fileName << ": " << std::strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}
