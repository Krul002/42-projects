/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:21:19 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/08 21:21:24 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include <iostream>
# include <string.h>
# include "AWeapon.hpp"

class PowerFist : public AWeapon {
private:
public:
	PowerFist();
	PowerFist(const PowerFist &weapon);
	virtual ~PowerFist();
	virtual void attack() const;
	PowerFist	&operator=(const PowerFist &weapon);
};

#endif