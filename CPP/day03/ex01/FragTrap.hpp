/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 11:07:37 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:25:18 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string.h>

class FragTrap {
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
	std::ostream		&nameCout(void);
	const std::string	damage(unsigned int amount);
	const std::string	target(std::string const & target);
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag);
	~FragTrap();
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		vaulthunter_dot_exe(std::string const & target);
	FragTrap	&operator=(const FragTrap &frag);
};

#endif
