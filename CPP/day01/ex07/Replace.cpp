/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:06:06 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:12:23 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace() {
	std::cout << "New Replacer!" << std::endl;
}

Replace::~Replace() {
	std::cout << "Delete Replacer!" << std::endl;
}

int	Replace::readFile(std::string name) {
	std::ifstream	fin;
	std::string		mem;
	fin.open(name);
	if (errno != 0)
		return (1);
	while (true) {
		std::getline(fin, mem);
		copy.append(mem);
		if (fin.eof() == true)
			break ;
		copy.append("\n");
	}
	fin.close();
	return (0);
}

int	Replace::replaceString(std::string str1, std::string str2) {
	std::size_t		len;
	std::size_t		j = 0;
	len = copy.length();
	if (str1 == str2) {
		past = copy;
		return (0);
	}
	for (std::size_t i = 0; i < len; i++) {
		i = copy.find(str1, j);
		if (i == std::string::npos) {
			past.append(copy, j, len);
			break ;
		}
		past.append(copy, j, i - j);
		past.append(str2);
		i += str1.length();
		j = i;
	}
	return (0);
}

int	Replace::writeFile(std::string name) {
	std::ofstream	fout;
	fout.open(name);
	if (errno != 0)
		return (1);
	fout << past;
	fout.close();
	return (0);
}
