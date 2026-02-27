/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:28:54 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/27 18:17:18 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::RPN(const RPN &other) : _values(other._values){}
RPN& RPN::operator= (const RPN &other){
	if (this != &other)
		_values = other._values;
	return *this;
}
RPN::~RPN(){}

/*
Si espace -> ignore
Si chiffre -> push
Si opérateur -> pop 2, calculer, push
Sinon -> erreur
*/

void RPN::calValues(const std::string& val)
{
    for (size_t i = 0; i < val.length(); ++i)
    {
        if (val[i] == ' ')
            continue;

        if (std::isdigit(val[i]))
            _values.push_back(val[i] - '0');

        else if (val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/'){
            if (_values.size() < 2)
                throw std::invalid_argument("Error");

            int b = _values.back();
            _values.pop_back();
            int a = _values.back();
            _values.pop_back();

            int result;

            if (val[i] == '+') result = a + b;
            else if (val[i] == '-') result = a - b;
            else if (val[i] == '*') result = a * b;
            else {
                if (b == 0) throw std::invalid_argument("Error");
                result = a / b;
            }
            _values.push_back(result);
        }
        else
            throw std::invalid_argument("Error");
    }

    if (_values.size() != 1)
        throw std::invalid_argument("Error");
    std::cout << _values.back() << std::endl;
}

/*

GOOD :
1 2 + 
8 9 * 9 - 9 - 9 - 4 - 1 + 

NOT GOOD:
1 2 3 + <-- 3 nombres a la suite
1 + <------ pas 2 nombre pour un operateur
+ <-------- op seul
1 0 / <---- division par 0

*/