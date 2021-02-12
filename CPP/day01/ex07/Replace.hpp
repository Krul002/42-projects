/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:05:09 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 01:05:54 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <cstring>

class	Replace {
private:
	std::string	copy;
	std::string	past;
public:
	Replace();
	~Replace();
	int	readFile(std::string name);
	int	replaceString(std::string str1, std::string str2);
	int	writeFile(std::string name);
};

#endif