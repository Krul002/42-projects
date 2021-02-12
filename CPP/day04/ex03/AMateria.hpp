/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:48:28 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:20:08 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string.h>

# include "ICharacter.hpp"

class AMateria {
private:
	std::string		_type;
	unsigned int	_xp;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &mat);
	virtual ~AMateria();
	std::string const	&getType() const;
	unsigned int		getXP() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
	AMateria			&operator=(const AMateria &mat);
};

#endif
