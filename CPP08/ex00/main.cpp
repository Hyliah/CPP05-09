/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:57:37 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/19 23:46:04 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
    // VECTOR
    std::vector<int> test1;
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);

    try {
        std::cout << "Vector 3: " << *easyfind(test1, 3) << std::endl;
        std::cout << "Vector 4: " << *easyfind2(test1, 4) << std::endl;

        std::cout << "Vector 8: " << *easyfind2(test1, 8) << std::endl;
        
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // DEQUE
    std::deque<int> test2;
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(4);
    test2.push_back(5);

    try {
        std::cout << "Deque 4: " << *easyfind(test2, 4) << std::endl;
        std::cout << "Deque 2: " << *easyfind2(test2, 2) << std::endl;

        std::cout << "Deque 9: " << *easyfind(test2, 9) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // LIST
    std::list<int> test3;
    test3.push_back(2);
    test3.push_back(3);
    test3.push_back(4);
    test3.push_back(5);

    try {
        std::cout << "List 2: " << *easyfind(test3, 2) << std::endl;
        std::cout << "List 5: " << *easyfind2(test3, 5) << std::endl;
    
        std::cout << "List 8: " << *easyfind2(test3, 8) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

/*
A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters:
the first one is of type T, and the second one is an integer.

Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as expected.
*/