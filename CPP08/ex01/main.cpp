/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:15:33 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/22 22:09:03 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(){
    std::srand(std::time(NULL));
    
    Span span0(3);
    Span span1(1000);
    Span span2(200);
    Span span3(5);

    std::cout << "------ creation of a defectuous one -------" << std::endl;
    span0.addNumber(1);

    std::cout << "------ creation of a big old vector -------" << std::endl;
    for (int i = 0; i < 1000; i++){
        try {span1.addNumber(::rand()); }
        catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    }


    std::cout << "------ try the try and catch -------" << std::endl;
    for (int i = 0; i < 201; i++){
        try {span2.addNumber(::rand()); }
        catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    }

   std::cout << "\n------ small an easy to test -------" << std::endl;

    span3.addNumber(2);
    span3.addNumber(12);
    span3.addNumber(29);
    span3.addNumber(11);
    span3.addNumber(3);

    std::cout << "------ test the longest and shortest span -------" << std::endl;
    try
    {
        std::cout << "\n -- shortest : 3 - 2 = 1 // longest : 29 - 12 = 17" << std::endl;
        std::cout << "Span3 shortest: " << span3.shortestSpan() << std::endl;
        std::cout << "Span3 longest : " << span3.longestSpan() << std::endl;
        std::cout << "\n -- test on the big one with random numbers" << std::endl;
        std::cout << "Span1 shortest: " << span1.shortestSpan() << std::endl;
        std::cout << "Span1 longest : " << span1.longestSpan() << std::endl;
        std::cout << "\n -- defectuous one" << std::endl;
        std::cout << "Span0 longest : " << span0.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}