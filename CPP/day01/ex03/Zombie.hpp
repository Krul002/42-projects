/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:02:35 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 01:23:31 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string.h>

class	Zombie {
private:
	std::string	type;
	std::string	name;
public:
	Zombie();
	Zombie(std::string z_name, std::string z_type);
	~Zombie();
	void anounce();
	std::string randomName();
	std::string randomType();
};

#endif
