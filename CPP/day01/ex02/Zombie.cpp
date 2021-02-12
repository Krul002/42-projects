/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:35:51 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 01:51:27 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	type = randomType();
	name = randomName();
	std::cout << "\033[1;32m\t\tZombie " << name << "(" << type << ") appeared!\033[0m" << std::endl;
}

std::string Zombie::randomName() {
	int len = rand() % 10;
	if (len < 1)	
		len = 5;
	std::string	name(len, ' ');
	std::string vower = "aeiouy";
	int		n = 0;
	char	c;
	for (int i = 0; i < len; i++) {
		c = rand() % 20 + 'a';
		if (strchr("aeiouy", c) == NULL)
			n++;
		if (n > 2) {
			n = rand() % 5;
			c = vower[n];
			n = 0;
		}
		if (i == 0)
			c += 'A' - 'a';
		name[i] = c;
	}
	return (name);
}

std::string Zombie::randomType() {
	std::string	t[] = {"type1", "type2", "type3", "type4"};
	int			i = rand() % 4;

	return (t[i]);
}

Zombie::Zombie(std::string z_name, std::string z_type) {
	type = z_type;
	name = z_name;
	std::cout << "\033[1;32m\t\tZombie " << name << "(" << type << ") appeared!\033[0m" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "\033[1;31m\t\tZombie " << name << "(" << type << ") is die!\033[0m" << std::endl;
}

void Zombie::anounce() {
	std::cout << "\033[1;35m\t\t<" << name << " (" << type << ")> Braiiiiiiinnnssss...\033[0m" << std::endl;
}
