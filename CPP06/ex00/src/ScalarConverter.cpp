/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:07:52 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/08 21:44:30 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsConvert.hpp"
#include "utilsSpecials.hpp"
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdlib.h>

static void checks(std::string& entry, int *nbF, int *nbL, int *nbD, bool *fLast, bool *dPlace);
static void suppressF(std::string* entry);

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

	// step 3 : check for words
	int nbF = 0;
	int nbL = 0;
	int nbD = 0;
	bool fLast = false;
	bool dPlace = true;

	checks(entry, &nbF, &nbL, &nbD, &fLast, &dPlace);
	if (nbF > 1 || nbL > 0 || (nbF == 1 && fLast == false) || nbD > 1 || dPlace == false)
		return (sendWord());
	
	// step 4 : supress the f is there's one
	if (nbF > 0)
		suppressF(&entry);

	// step 5 : convert 
	if (nbD == 1)
	 	return (convertDecimal(&entry));
	
	return (convertInt(&entry));
	
}

static void checks(std::string& entry, int *nbF, int *nbL, int *nbD, bool *fLast, bool *dPlace){
	size_t len = entry.length();
	for (size_t i = 0 ; i < len ; i++){
		char c = entry[i];
		if (i == 0 && !std::isdigit(c) && c != '+' && c != '-') 
			(*nbL)++;
		if (i > 0 && !std::isdigit(c) && c != 'f' && c != '.')
			(*nbL)++;
		if (c == 'f')
			(*nbF)++;
		if (c == '.'){
			(*nbD)++;
			if ((i == 0 || i == (len - 1)) && (i == (len - 2) && entry[i + 1] == 'f'))
				(*dPlace) = false;
		}
		if (i == entry.length() - 1 && c == 'f')
			(*fLast) = true;
	}
}

static void suppressF(std::string* entry) {
	std::string result;
	for (size_t i = 0; i < entry->length(); i++) {
		if ((*entry)[i] != 'f') {
			result += (*entry)[i];
		}
	}
	*entry = result;
}




// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

// faire un check et créer une liste de pointeur sur fonctions et les fonctions qui vont avec pour les inf et nan trucs OK
// faire une verification, si y a 1f -> c est un float, si y en a plusieurs c est une erreur
// enlever le f si y en a un.
// faire les convertion like a boss 

// si 0 : Non displayable | si non : impossible | si nombre : '*' <- si entre 0 et 255 sinon impossible



// static int checkLetters(const std::string& entry) {
//     int count = 0;
//     for (size_t i = 0; i < entry.length(); i++) {
//         char c = entry[i];
//         if (!std::isdigit(c) && c != 'f' && c != '+' && c != '-' && c != '.') {
//             count++;
//         }
//     }
//     return count;
// }