/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:15:39 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/08 22:02:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsConvert.hpp"
#include "utilsSpecials.hpp"
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdlib.h>

void convertInt(std::string *entry){
    bool sNotation = false;
    if (entry->length() > 6)
        sNotation = true;
	//c_str() -> convert std::string to char*
	// str to ll -> beg of char*, end of char* , base 
	char* end;
	long long llongNB = strtoll(entry->c_str(), &end, 10);

    //erno pcq ca met que les plus gros possible

	//empty string or weird characters:
	if (end == entry->c_str() || *end != '\0')
		return (sendWord());

	//char 
	if (llongNB >= 0 && llongNB < 32)
		std::cout << "char: non displayable" << std::endl;
	else if (llongNB >= 32 && llongNB <= 126)
		std::cout << "char: '" << static_cast<unsigned char>(llongNB) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	//int
	if (llongNB <= INT_MAX && llongNB >= INT_MIN)
		std::cout << "int: " << llongNB << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	
	//float
	if (llongNB <= FLT_MAX && llongNB >= -FLT_MAX){
        if (sNotation == false)
		    std::cout << "float: " << static_cast<float>(llongNB) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(llongNB) << "f" << std::endl;
    }
	else if (llongNB > FLT_MAX)
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: -inff" << std::endl;

	//double
	if (llongNB <= DBL_MAX && llongNB >= -DBL_MAX){
        if (sNotation == false)
		    std::cout << "double: " << static_cast<double>(llongNB) << ".0"<< std::endl;
        else
            std::cout << "double: " << static_cast<double>(llongNB) << std::endl;
    }
	else if (llongNB > DBL_MAX)
		std::cout << "double: +inff" << std::endl;
	else
		std::cout << "double: -inff" << std::endl;	
}

void convertChar(int c){

	//char 
	if ((c > 0 && c < 32) || c == 127)
		std::cout << "char: non displayable" << std::endl;
	else 
		std::cout << "char: '" << static_cast<unsigned char>(c) << "'" << std::endl;
	//int
	std::cout << "int: " << c << std::endl;
	//float
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	//double
	std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
}

void convertDecimal(std::string *entry){
	char* end;
	double dblNB = strtod(entry->c_str(), &end);

	if (end == entry->c_str() || *end != '\0')
		return (sendWord());

	//char 
	if (static_cast<int>(dblNB) >= 0 && static_cast<int>(dblNB) < 32)
		std::cout << "char: non displayable" << std::endl;
	else if (static_cast<int>(dblNB) >= 32 && static_cast<int>(dblNB) <= 126)
		std::cout << "char: '" << static_cast<unsigned char>(dblNB) << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	//int
	if (dblNB <= INT_MAX && dblNB >= INT_MIN)
		std::cout << "int: " << static_cast<int>(dblNB) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;
	
	//float
    if (std::isnan(dblNB))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(dblNB))
        std::cout << "float: " << (dblNB > 0 ? "+inff" : "-inff") << std::endl;
    else{
        if (dblNB == static_cast<long long>(dblNB))
            std::cout << "float: " << dblNB << ".0f" << std::endl;
        else
            std::cout << "float: " << dblNB << "f" << std::endl;
    }

	//double
	if (dblNB == static_cast<long long>(dblNB))
        std::cout << "double: " << dblNB << ".0" << std::endl;
    else
        std::cout << "double: " << dblNB << std::endl;
}
