/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:18:51 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/06 12:02:27 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string.h>

class Weapon {
private:
	std::string	_type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string	&getType();
	void				setType(std::string type);
};

#endif