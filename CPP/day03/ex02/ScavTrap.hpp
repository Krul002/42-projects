/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 22:36:07 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:28:40 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
protected:
	virtual std::string	damage(std::string target, std::string mode, unsigned int amount);
	virtual std::string	destroy(int n);
	virtual std::string	notEnergy();
	virtual std::string	reparo(unsigned int amount);
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scav);
	virtual ~ScavTrap();
	void	challengeNewcomer(std::string const & target);
	ScavTrap		&operator=(const ScavTrap &scav);
};

#endif