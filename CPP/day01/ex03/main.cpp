/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:01:20 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 13:10:49 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ZombieHorde.hpp"

int		ft_stoi(std::string s) {
	int		len;
	int		n;

	len = s.length();
	n = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i]) == 0)
			return (-1);
		n = n * 10 + s[i] - '0';
	}
	return (n);
}

int		main() {
	std::string	type;
	std::string	circle;
	int			N;
	ZombieHorde	*event;

	circle = "yes";
	std::cout << "\033[1;32mWelcome to our zombie event!\033[0m" << std::endl << std::endl;
	while (circle == "yes")	{
		int		i = 0;
		while (i == 0) {
			std::cout << "\033[1;34m\tCreate new zombies? (yes/no)" << std::endl << "\t";
			std::getline(std::cin, circle);
			if (std::cin.eof()) {
				std::cout << "no" << std::endl;
				circle = "no";	
			}
			if (circle == "yes" || circle == "no")
				i = 1;
			else
				std::cout << "\033[1;31m\tOnly yes or no!\033[1;34m" << std::endl;
		}
		if (circle == "no")
			break ;
		std::cout << std::endl;
		i = 0;
		while (i == 0) {
			std::cout << "\033[1;34m\tHow many zombies?" << std::endl << "\t";
			std::getline(std::cin, type);
			if (std::cin.eof()) {
				std::cout << "STOP" << std::endl;
				i = 2;
				break ;
			}
			N = ft_stoi(type);
			if (N >= 0)
				i = 1;
			else
				std::cout << "\033[1;31m\tDigit please!\033[1;34m" << std::endl;
		}
		if (i > 1)
			break ;
		std::cout << std::endl;
		std::cout << "\033[1;34m";
		event = new ZombieHorde(N);
		event->anounce();
		delete event;
	}
	std::cout << std::endl << "\033[1;31mThis concludes our zombie event!\033[0m" << std::endl;
	return (0);
}
