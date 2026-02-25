/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:35:34 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/25 18:02:37 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

class BitcoinExchange{
    private :
        std::map<std::string, double> _data;
        bool checkData(const std::string &date);

    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator= (const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadData(const std::string &data);
        double dataComp(const std::string &av);
        void parseDataToMap(std::ifstream& file);
};