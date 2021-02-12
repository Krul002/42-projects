/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:25:46 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/07 09:49:14 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:
	int					value;
	static const int	FRACT_BITS;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;
	Fixed			&operator =(const Fixed &fixed);
};

std::ostream	&operator<<(std::ostream &fd, const Fixed &fixed);

#endif
