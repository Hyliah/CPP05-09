/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:00:21 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/03 02:01:57 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b){
	return (a < b) ? a : b;
}

template <typename T>
void swap(T& a, T& b){
	T temp = a;
	a = b;
	b = temp;
}


#endif

// Implement the following function templates:

// • swap: Swaps the values of two given parameters. Does not return anything.

// • min: Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.

// • max: Compares the two values passed as parameters and returns the greatest one.
// If they are equal, it returns the second one.

// These functions can be called with any type of argument. The only requirement is
// that the two arguments must have the same type and must support all the comparison
// operators.