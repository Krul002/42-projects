/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:14:37 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:21:58 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &mat);
	virtual ~Cure();
	virtual Cure	*clone() const;
	virtual void		use(ICharacter &target);
	Cure			&operator=(const Cure &mat);
};

#endif
