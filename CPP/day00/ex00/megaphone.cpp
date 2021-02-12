/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 14:07:44 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 01:32:31 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int		main(int size, char **args) {
	int		len;

	if (size == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < size; i++) {
		len = strlen(args[i]);
		for (int j = 0; j < len; j++)
			if (islower(args[i][j]))
				args[i][j] += 'A' - 'a';
		std::cout << args[i];
	}
	std::cout << std::endl;
	return (0);
}
