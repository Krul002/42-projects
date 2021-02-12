/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:37:32 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 12:58:03 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() {
	this->type = "";
	std::cout << "\033[1;32mWelcome to our zombie event!\033[0m" << std::endl << std::endl;
}

ZombieEvent::~ZombieEvent() {
	std::cout << std::endl << "\033[1;31mThis concludes our zombie event!\033[0m" << std::endl;
}

void	ZombieEvent::setZombieType(std::string type) {
	this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
	return (new Zombie(name, type));
}

void	ZombieEvent::randomChump() {
	Zombie	*zombie = newZombie(Zombie::randomName());
	zombie->anounce();
	delete zombie;
}
