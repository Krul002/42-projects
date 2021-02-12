/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:02:21 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 12:57:31 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class	ZombieEvent {
private:
	std::string	type;
public:
	ZombieEvent();
	~ZombieEvent();
	void	setZombieType(std::string s);
	void	randomChump();
	Zombie* newZombie(std::string name);
};

#endif
