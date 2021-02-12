/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:23:26 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/05 14:23:37 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap() {
	Pony	*pony = new Pony("Applejack", "Orange", "Heap", "Apple", 100, 100, 100);
	
	std::cout << "\033[1;34m-|-----------------------------------------------------------|-" << std::endl;
	std::cout << " |==================>     Heap Pony       <==================| " << std::endl;
	std::cout << "-|-----------------------------------------------------------|-\033[0m" << std::endl << "\033[1;33m";
	pony->aboutPony();
	std::cout << "\033[0m";
	delete pony;
}

void	ponyOnTheStack() {
	Pony	pony("Twilight Sparkle", "Purple", "Stack", "Knowledge", 100, 100, 100);
	std::cout << "\033[1;34m-|-----------------------------------------------------------|-" << std::endl;
	std::cout << " |==================>     Stack Pony      <==================| " << std::endl;
	std::cout << "-|-----------------------------------------------------------|-\033[0m" << std::endl << "\033[1;35m";
	pony.aboutPony();
	std::cout << "\033[0m";
}

int		main() {
	Pony	pony("Zero", "", "Stack", "", 0, 0, 0);
	std::cout << std::endl << "\033[1;31m!!!Create Zero pony Stack breed!!!\033[0m" << std::endl << std::endl;
	ponyOnTheStack();
	ponyOnTheHeap();
}
