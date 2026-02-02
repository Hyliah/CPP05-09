/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:15:39 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/03 00:49:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsConvert.hpp"
#include "utilsSpecials.hpp"
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

void convertRest(const std::string &entry)
{
    char *end;
    double value = std::strtod(entry.c_str(), &end);

    if (*end != '\0' && !(end[0] == 'f' && end[1] == '\0'))
    {
        sendWord();
        return;
    }

    // NaN / inf check 
    bool isNan = (value != value);
    bool isInf = (value == 1.0 / 0.0 || value == -1.0 / 0.0);

    // CHAR
    if (isNan || isInf || value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(value) << "'\n";

    // INT
    if (isNan || isInf || value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << static_cast<int>(value) << "\n";

    // FLOAT
    float f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f\n";

    // DOUBLE
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "\n";
}



void convertChar(int c){

	//CHAR
	if ((c > 0 && c < 32) || c == 127)
		std::cout << "char: non displayable" << std::endl;
	else 
		std::cout << "char: '" << static_cast<unsigned char>(c) << "'" << std::endl;

	//INT
	std::cout << "int: " << c << std::endl;

	//FLOAT
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

	//DOUBLE
	std::cout << "double: " << static_cast<double>(c) << ".0"<< std::endl;
}
