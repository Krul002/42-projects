/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 23:45:25 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:29:21 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap {
protected:
	virtual std::string	damage(std::string target, std::string mode, unsigned int amount);
	virtual std::string	destroy(int n);
	virtual std::string	notEnergy();
	virtual std::string	reparo(unsigned int amount);
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &ninja);
	virtual ~NinjaTrap();
	void	ninjaShoebox(ClapTrap &clap);
	void	ninjaShoebox(FragTrap &frap);
	void	ninjaShoebox(ScavTrap &scav);
	void	ninjaShoebox(NinjaTrap &ninja);
	NinjaTrap		&operator=(const NinjaTrap &ninja);
};

#endif