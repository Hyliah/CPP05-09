/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:15:39 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/21 18:46:55 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utilsConvert.hpp"
#include "utilsSpecials.hpp"
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <stdlib.h>

void convertRest(const std::string &entry)
{
    char *end;
    double value = std::strtod(entry.c_str(), &end);

    // verification
    if (*end != '\0' && !(end[0] == 'f' && end[1] == '\0'))
    {
        sendWord();
        return;
    }

    // CHAR
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossible\n";
    else if (!isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << static_cast<char>(value) << "'\n";

    // INT
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
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
