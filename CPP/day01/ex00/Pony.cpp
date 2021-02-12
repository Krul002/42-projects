/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:10:07 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 01:43:46 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string p_name, std::string p_color, std::string p_breed, std::string f_food, int p_weight, int p_height, int p_speed) {
	setName(p_name);
	setColor(p_color);
	setBreed(p_breed);
	setFood(f_food);
	setWeight(p_weight);
	setHeight(p_height);
	setSpeed(p_speed);
}

Pony::~Pony() {
	std::cout << "\033[1;32mDelete pony: " << this->name << " breed: " << this->breed << "\033[0m" << std::endl << std::endl;
}

void	Pony::setName(std::string s) {
	this->name = s;
}

void	Pony::setColor(std::string s) {
	this->color = s;
}

void	Pony::setBreed(std::string s) {
	this->breed = s;
}

void	Pony::setFood(std::string s) {
	this->favorite_food = s;
}

void	Pony::setWeight(int i) {
	this->weight = i;
}

void	Pony::setHeight(int i) {
	this->height = i;
}

void	Pony::setSpeed(int i) {
	this->speed = i;
}

void	Pony::aboutPony() {
	std::cout << "Hello! This pony's name is " << this->name;
	std::cout << ".\nHer coat is " << this->color << ", as she is of the " << this->breed << " breed.";
	std::cout << " She loves " << this->favorite_food << " very much.\nWith a height of " << this->height;
	std::cout << " cm and a weight of " << this->weight;
	std::cout << " kg, she can reach speeds of " << this->speed << " km / h." << std::endl;
}
