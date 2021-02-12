/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 21:43:59 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/11 02:29:44 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
protected:
	virtual std::string	damage(std::string target, std::string mode, unsigned int amount);
	virtual std::string	destroy(int n);
	virtual std::string	notEnergy();
	virtual std::string	reparo(unsigned int amount);
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &frag);
	virtual ~FragTrap();
	void	vaulthunter_dot_exe(std::string const & target);
	FragTrap		&operator=(const FragTrap &frag);
};

#endif