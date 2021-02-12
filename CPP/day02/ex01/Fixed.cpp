/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:44:31 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/12 15:00:50 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::FRACT_BITS = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	value = val << FRACT_BITS;
}
Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(val * (1 << FRACT_BITS));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int				Fixed::getRawBits(void) const {
	return (value);
}

void			Fixed::setRawBits(int const raw) {
	value = raw;
}

float			Fixed::toFloat(void) const {
	return ((float)value / (1 << FRACT_BITS));
}
int				Fixed::toInt(void) const {
	return (value >> FRACT_BITS);
}

Fixed			&Fixed::operator=(const Fixed &fixed) {
	std::cout << "Assignation operator called" << std::endl;
	value = fixed.getRawBits();
	return (*this);
}

std::ostream	&operator <<(std::ostream &fd, const Fixed &fixed) {
	return (fd << fixed.toFloat());
}
