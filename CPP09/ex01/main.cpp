/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:30:04 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/09 02:36:51 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av){
    if (ac != 2){
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        rpn.calValues(av[1]);
    }
    catch (std::exception &e){
		std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
