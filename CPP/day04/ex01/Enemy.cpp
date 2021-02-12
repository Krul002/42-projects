/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:18:49 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:19:07 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() {
	this->type = "_";
	this->hp = 10;
}

Enemy::Enemy(int hp, std::string const & type) {
	this->hp = hp;
	this->type = type;
}

Enemy::Enemy(const Enemy &enemy) {
	*this = enemy;
}

Enemy	&Enemy::operator=(const Enemy &enemy) {
	this->hp = enemy.hp;
	this->type = enemy.type;
	return (*this);
}

Enemy::~Enemy() {
}

void	Enemy::takeDamage(int damage) {
	if (damage >= 0) {
		if (damage > hp)
			hp = 0;
		else
			hp -= damage;
	}
}

const std::string	Enemy::getType() const {
	return (this->type);
}

int		Enemy::getHP() const {
	return (this->hp);
}
