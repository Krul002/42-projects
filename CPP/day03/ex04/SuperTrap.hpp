/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:38:12 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:29:56 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "ClapTrap.hpp"
# include "NinjaTrap.hpp"
# include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
protected:
	virtual std::string	damage(std::string target, std::string mode, unsigned int amount);
	virtual std::string	destroy(int n);
	virtual std::string	notEnergy();
	virtual std::string	reparo(unsigned int amount);
public:
	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &super);
	virtual ~SuperTrap();
	SuperTrap		&operator=(const SuperTrap &super);
};

#endif
