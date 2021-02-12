/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalt <cmalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:33:30 by cmalt             #+#    #+#             */
/*   Updated: 2021/01/24 06:20:51 by cmalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>
typename T::iterator   easyfind(T &container, int n) {
    typename T::iterator    end = container.end();
    for (typename T::iterator iter = container.begin(); iter != end; iter++)
        if (*iter == n)
            return iter;
    return end;
}

#endif