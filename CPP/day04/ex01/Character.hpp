/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:05:45 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:52:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string.h>

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character {
private:
	std::string	name;
	int			AP;
	AWeapon		*weapon;
public:
	Character();
	Character(const Character &character);
	Character(std::string const &name);
	~Character();
	Character	&operator=(const Character &character);
	std::string	getStatus() const;
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	const std::string getName() const;
};

std::ostream	&operator<<(std::ostream &fd, const Character &character);

#endif