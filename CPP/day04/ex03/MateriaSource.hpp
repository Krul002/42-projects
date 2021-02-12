/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 02:33:41 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/09 16:22:54 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria	*inventory[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &mat);
	virtual ~MateriaSource();
	virtual void		learnMateria(AMateria *);
	virtual AMateria	*createMateria(std::string const &type);
	MateriaSource		&operator=(const MateriaSource &mat);
};

#endif