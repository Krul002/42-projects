/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:36:10 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 09:36:30 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base	*generate(void) {
	int	random = rand() % 3;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void	identify_from_pointer(Base *p) {
	if (dynamic_cast<A*>(p) != 0)
		std::cout << "A" <<std::endl;
	if (dynamic_cast<B*>(p) != 0)
		std::cout << "B" <<std::endl;
	if (dynamic_cast<C*>(p) != 0)
		std::cout << "C" <<std::endl;
}

void	identify_from_reference(Base &p) {
	identify_from_pointer(&p);
}
