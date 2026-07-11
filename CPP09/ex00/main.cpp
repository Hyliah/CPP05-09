/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:33 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/09 02:30:53 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    try {
        btc.loadData("data.csv");
        btc.dataComp(av[1]);
    }
    catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
        return 1;
	} 
    return 0;
}