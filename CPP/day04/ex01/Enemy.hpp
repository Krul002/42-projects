/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 20:04:48 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:19:04 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>
# include <string.h>

class Enemy {
private:
	int			hp;
	std::string	type;
public:
	Enemy();
	Enemy(const Enemy &enemy);
	Enemy(int hp, std::string const & type);
	virtual ~Enemy();
	virtual void takeDamage(int);
	const std::string getType() const;
	int getHP() const;
	Enemy	&operator=(const Enemy &enemy);
};

#endif
