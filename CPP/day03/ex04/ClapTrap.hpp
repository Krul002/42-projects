/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:10:57 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:29:39 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string.h>

class ClapTrap {
private:
	unsigned int	HP;
	unsigned int	MaxHP;
	unsigned int	EP;
	unsigned int	MaxEP;
	unsigned int	Lvl;
	std::string		Name;
	std::string		Model;
	unsigned int	meleeAttackDamage;
	unsigned int	rangedAttackDamage;
	unsigned int	reductArmorDamage;
protected:
	virtual std::string	damage(std::string target, std::string mode, unsigned int amount);
	virtual std::string	destroy(int n);
	virtual std::string	notEnergy();
	virtual std::string	reparo(unsigned int amount);
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hp, unsigned int maxHp, unsigned int ep, unsigned int maxEp, unsigned int lvl, unsigned int meleeDamage, unsigned int rangedDamage, unsigned int armor);
	ClapTrap(const ClapTrap &clap);
	virtual ~ClapTrap();
	void			rangedAttack(std::string const & target);
	void			meleeAttack(std::string const & target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName();
	unsigned int	getHP();
	void			setHP(unsigned int amount);
	void			setModel(std::string s);
	unsigned int	getMaxEnergy();
	unsigned int	getEnergy();
	void			setEnergy(unsigned int ep);
	ClapTrap		&operator=(const ClapTrap &clap);
};

#endif
