/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:52:18 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:19:30 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include <iostream>
# include <string.h>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
private:
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &weapon);
	virtual ~PlasmaRifle();
	virtual void attack() const;
	PlasmaRifle	&operator=(const PlasmaRifle &weapon);
};

#endif
