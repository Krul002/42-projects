/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 09:28:05 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/19 09:37:23 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int		main() {
	srand(time(NULL));
	time_t	timer;
	Base	*base;
	int		numTests = 7;
	for (int i = 0; i < numTests; i++) {
		std::cout << "Test " << i + 1 << ":" << std::endl;
		base = generate();
		std::cout << "pointer: ";
		identify_from_pointer(base);
		std::cout << "pointer: ";
		identify_from_reference(*base);
		timer = time(NULL) + rand() % 2 + 1;
		while (i + 1 < numTests && time(NULL) < timer);
		delete base;
	}
	return 0;
}
