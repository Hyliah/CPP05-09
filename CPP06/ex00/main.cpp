/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:08:58 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/08 01:30:16 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Please enter (only) one element to convert" << std::endl;
        return (1);
    }
    
    ScalarConverter.convert(av[1]);
    return (0);
}



/*
Write a program to test that your class works as expected.
You have to first detect the type of the literal passed as a parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values.
*/

// EXEMPLE :
// ./convert 0
// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

// ./convert nan
// char: impossible
// int: impossible
// float: nanf
// double: nan

// ./convert 42.0f
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0