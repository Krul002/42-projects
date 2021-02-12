/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:26:42 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 16:27:43 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string.h>

class ScavTrap {
private:
	unsigned int	HP;
	unsigned int	MaxHP;
	unsigned int	EP;
	unsigned int	MaxEP;
	unsigned int	Lvl;
	std::string		Name;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	reductArmorDamage;
protected:
	std::ostream			&nameCout(void);
	const std::string		damage(unsigned int amount);
	const std::string		target(std::string const & target);
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scav);
	~ScavTrap();
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	challengeNewcomer(std::string const & target);
	ScavTrap		&operator=(const ScavTrap &scav);
};

#endif