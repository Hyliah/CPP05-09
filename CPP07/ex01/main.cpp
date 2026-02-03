/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 02:39:08 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/03 03:08:24 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <iostream>
#include <string>
#include "iter.hpp"


int main()
{
    std::cout << "\n--------- ARRAY - INT ---------" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Before increment: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    iter(arr, len, increment);

    std::cout << "After increment: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    std::cout << "\n--------- ARRAY - INT - CONST ---------" << std::endl;
    const int constArr[] = {10, 20, 30};
    
    std::cout << "Const array: ";
    iter(constArr, 3, print<int>);
    std::cout << std::endl;

   
    std::cout << "\n--------- ARRAY - STRINGS ---------" << std::endl;
    std::string words[] = {"hello", "world"};
    
    std::cout << "Strings: ";
    iter(words, 2, print<std::string>);
    std::cout << std::endl;

    return 0;
}

