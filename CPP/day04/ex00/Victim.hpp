/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:23:33 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 16:22:00 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string.h>

class Victim {
private:
	std::string	name;
public:
	Victim();
	Victim(std::string	name);
	Victim(const Victim &victim);
	virtual ~Victim();
	std::string	getName() const;
	void		setName(std::string name);
	Victim	&operator=(const Victim &victim);
	virtual void getPolymorphed() const;
};

std::ostream	&operator<<(std::ostream &fd, const Victim &victim);

#endif