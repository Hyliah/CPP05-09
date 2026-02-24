/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:35:34 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/24 16:36:08 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

class BitcoinExchange{
    private :
        std::map<std::string, double> _data;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator= (const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadData(const std::string &data);
        double dataComp(const std::string &av);
        void parseDataToMap(std::ifstream file);
};