/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:07:52 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/21 18:41:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsConvert.hpp"
#include "utilsSpecials.hpp"
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdlib.h>

void ScalarConverter::convert(std::string entry){

	std::string entryCopy = entry;
	// step 1 : check for special words
	std::transform(entryCopy.begin(), entryCopy.end(), entryCopy.begin(), ::tolower);
	static const char * tab[6] = {"nan", "nanf", "+inff", "-inff", "+inf", "-inf"};
	void (*p[6])( void ) = {sendNan, sendNanf, sendinffp, sendinffn, sendinfp, sendinfn};

	for (int i = 0 ; i < 6 ; i++){
		if (entryCopy == tab[i])
			return (p[i]());
	}

	// step 2 : check if just 1 ascii
	if ((entry.length() == 1) && ((entry[0] > 0 && entry[0] <= 47) || (entry[0] > 57 && entry[0] <= 127))){
		return (convertChar(entry[0]));
	}
	
	convertRest(entry);
}
