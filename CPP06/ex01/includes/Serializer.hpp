/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:51:33 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/05 13:40:14 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
	private :
	
	public :
		// will not be initializable 
		
		// Serializer();
		// Serializer(const Serializer &other);
		// Serializer& operator=(const Serializer &other);
		// ~Serializer();
		
		static uintptr_t serialize(Data* ptr);
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		
		static Data* deserialize(uintptr_t raw);
		// It takes an unsigned integer parameter and converts it to a pointer to Data.
};

#endif

// Implement a class Serializer, which will not be initializable by the user in any way,
// with the following static methods:

