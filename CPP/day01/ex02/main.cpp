/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:01:20 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 13:01:26 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ZombieEvent.hpp"

// Zombie* randomChump(ZombieEvent &event) {
// 	int len = rand() % 10;
// 	if (len < 1)	
// 		len = 5;
// 	std::string	name(len, ' ');
// 	std::string vower = "aeiouy";
// 	int		n = 0;
// 	char	c;
// 	for (int i = 0; i < len; i++) {
// 		c = rand() % 20 + 'a';
// 		if (strchr("aeiouy", c) == NULL)
// 			n++;
// 		if (n > 2) {
// 			n = rand() % 5;
// 			c = vower[n];
// 			n = 0;
// 		}
// 		if (i == 0)
// 			c += 'A' - 'a';
// 		name[i] = c;
// 	}
// 	return (event.newZombie(name));
// }

int		main() {
	std::string	type;
	std::string	circle;
	ZombieEvent	event;

	circle = "yes";
	srand(time(0));
	while (circle == "yes")	{
		int		i = 0;
		while (i == 0) {
			std::cout << "\033[1;34m\tCreate new zombie? (yes/no)" << std::endl << "\t";
			std::getline(std::cin, circle);
			if (std::cin.eof()) {
				std::cout << "no" << std::endl;
				return (0);
			}
			if (circle == "yes" || circle == "no")
				i = 1;
			else
				std::cout << "\033[1;31m\tOnly yes or no!\033[1;34m" << std::endl;
		}
		if (circle == "no")
			break ;
		std::cout << "\033[1;33m\tEnter the type of zombie: ";
		std::getline(std::cin, type);
		if (std::cin.eof()) {
			std::cout << "STOP" << std::endl;
			return (0);
		}
		std::cout << "\033[1;34m";
		event.setZombieType(type);
		event.randomChump();
	}
	return (0);
}
