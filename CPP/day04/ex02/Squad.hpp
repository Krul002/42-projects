/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:04:07 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 00:37:14 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad {
private:
	ISpaceMarine	**squad;
	int				size;
public:
	Squad();
	Squad(const Squad &squad);
	virtual ~Squad();
	virtual int				getCount() const;
	virtual ISpaceMarine	*getUnit(int) const;
	virtual int				push(ISpaceMarine *);
	Squad					&operator=(const Squad &squad);
};

#endif