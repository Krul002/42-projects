/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:16:18 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 01:54:25 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde() {
	std::cout << "\033[1;32m\tFor the Horde!\033[0m" << std::endl;
	zombie = new Zombie[1];
	num = 1;
}

ZombieHorde::ZombieHorde(int N) {
	std::cout << "\033[1;32m\tFor the Horde!\033[0m" << std::endl;
	zombie = new Zombie[N];
	num = N;
}

void	ZombieHorde::anounce() {
	for (int i = 0; i < num; i++) {
		zombie[i].anounce();
	}
}

ZombieHorde::~ZombieHorde() {
	delete [] zombie;
	std::cout << "\033[1;31m\tFor the Alliance!\033[0m" << std::endl;
}
