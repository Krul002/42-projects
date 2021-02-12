/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:54:56 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/14 13:42:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string.h>
# include "Victim.hpp"

class Sorcerer {
private:
	std::string	name;
	std::string	title;
public:
	Sorcerer();
	Sorcerer(std::string	name, std::string	title);
	Sorcerer(const Sorcerer &sorcerer);
	~Sorcerer();
	std::string	getName() const;
	std::string	getTitle() const;
	Sorcerer	&operator=(const Sorcerer &sorcerer);
	void		polymorph(Victim const &) const;
};


std::ostream	&operator<<(std::ostream &fd, const Sorcerer &sorcerer);

#endif
