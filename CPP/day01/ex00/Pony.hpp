/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:07:53 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 01:22:42 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string.h>

class	Pony {
private:
	int				weight;
	int				height;
	int				speed;
	std::string		name;
	std::string		color;
	std::string		breed;
	std::string		favorite_food;
public:
	Pony(std::string name, std::string color, std::string breed, std::string f_food, int weight, int height, int speed);
	~Pony();
	void	setName(std::string s);
	void	setColor(std::string s);
	void	setBreed(std::string s);
	void	setFood(std::string s);
	void	setWeight(int i);
	void	setHeight(int i);
	void	setSpeed(int i);
	void	aboutPony();
};

#endif
