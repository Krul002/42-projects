/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 08:13:05 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/23 07:51:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main() {
	void	*s;
	Data	*data;
	char	*s1;

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		s = serialize();
		std::cout << sizeof(static_cast<char*>(s)) << std::endl;
		data = deserialize(s);
		s1 = static_cast<char*>(s);
		std::cout << "Test " << i + 1 << ":" << std::endl;
		std::cout << "data->s1 = \"" << data->s1 << "\"" << std::endl;
		std::cout << "data->n = \"" << data->n << "\"" << std::endl;
		std::cout << "data->s2 = \"" << data->s2 << "\"" << std::endl; 
		delete [] s1;
		delete data;	
	}
	return 0;
}
