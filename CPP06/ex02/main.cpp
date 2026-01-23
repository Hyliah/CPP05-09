/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:15:38 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/23 16:10:17 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DynCastFunc.hpp"

int main(){
    std::srand(std::time(NULL)); //initialization for the random number generator 

    std::cout << "------ Multiple unknown Bases genereted ------" << std::endl;
    Base *base1 = generate();
    Base *base2 = generate();
    Base *base3 = generate();
    Base *base4 = generate();

    std::cout << "\n------ Dynamic cast with pointer ------" << std::endl;
    identify(base1);
    identify(base2);
    identify(base3);
    identify(base4);

    std::cout << "\n------ Dynamic cast with references ------" << std::endl;
    identify(*base1);
    identify(*base2);
    identify(*base3);
    identify(*base4);

    std::cout << "\n------ Delete and end the program ------" << std::endl;
    delete base1;
    delete base2; 
    delete base3; 
    delete base4;

    return 0;
}