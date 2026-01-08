/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:07:52 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/08 02:23:46 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsSpecials.hpp

static int checkF(std::string& entry);
static int checkLetters(const std::string& entry);
static void suppressF(std::string* entry);

void ScalarConverter::convert(std::string entry){

	// step 1 : check for special words
	std::transform(entry.begin(), entry.end(), entry.begin(), ::tolower);
	static const char * tab[6] = {"nan", "nanf", "+inff", "-inff", "+inf", "-inf"};
	void (*p[6])( void ) = {sendNan, sendNanf, sendinffp, sendinffn, sendinfp, sendinfn};

	for (int i = 0 ; i < 6 ; i++){
		if (entry == tab[i])
			return (p[i]());
	}

	// step 2 : check for words
	int nbF = checkF(entry);
	int nbL = checkLetters(entry);
	if (nbF > 1 || nbL > 0)
		return (sendWord());
	
	// step 3 : supress the f is there's one
	if (nbF > 0)
		suppressF(&entry);

	convert(entry);
}

static int checkF(std::string& entry){
	int f = 0;

	for (size_t i = 0 ; i < entry.length() ; i++){
		if (static_cast<unsigned char>(entry[i]) == 'f')
			f++;
	}
	return (f);
}

static int checkLetters(const std::string& entry) {
    int count = 0;
    for (size_t i = 0; i < entry.length(); i++) {
        char c = entry[i];
        if (!std::isdigit(c) && c != 'f' && c != '+' && c != '-' && c != '.') {
            count++;
        }
    }
    return count;
}

static void suppressF(std::string* entry) {
    std::string result;
    for (size_t i = 0; i < entry.length(); i++) {
        if ((*entry)[i] != 'f') {
            result += (*entry)[i];
        }
    }
    *entry = result;
}

static void convert(char * entry){
	
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