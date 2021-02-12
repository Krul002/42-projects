/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:06:37 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:22:26 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &mat);
	// [...]
	virtual ~Ice();
	virtual Ice	*clone() const;
	virtual void		use(ICharacter &target);
	Ice			&operator=(const Ice &mat);
};

#endif
