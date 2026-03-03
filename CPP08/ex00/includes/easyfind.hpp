/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:58:27 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/19 23:42:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>

//version without algorithm
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;

    for (it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
            return it;
    }
    throw std::out_of_range("Value not found");
}


//version with algotithm
#include <algorithm>

template <typename T>
typename T::iterator easyfind2(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::out_of_range("Value not found");
    return it;
}

