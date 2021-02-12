/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:36:12 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 15:21:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PEON_HPP
#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string.h>
# include "Victim.hpp"

class Peon : public Victim {
private:
public:
	Peon();
	Peon(std::string	name);
	Peon(const Peon &peon);
	virtual ~Peon();
	Peon	&operator=(const Peon &peon);
	virtual void getPolymorphed() const;
};

#endif