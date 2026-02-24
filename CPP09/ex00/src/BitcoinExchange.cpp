/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:11 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/24 17:25:04 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <map>

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data){}
BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange &other){
    if (this != &other)
        _data = other._data;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::parseDataToMap(std::ifstream& file)
{
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::size_t pos = line.find(','); //find ici est de std et pas la stl (begin, end, value)

        if (pos == std::string::npos)
            throw std::invalid_argument("Error: bad format.");

        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        char* end;
        double value = std::strtod(valueStr.c_str(), &end); //ne prendra que les caractères valide. met a jour end

        if (*end != '\0') // si caractère invalide, on sera pas a la fin
            throw std::invalid_argument("Error: invalid number.");

        _data.insert(std::make_pair(date, value));
    }
}
// voir pour la gestion d erreur car mes throw a des moments doivent quieter en mode no thanks ou jsute passer a la ligne suivante, A voir. 
void BitcoinExchange::loadData(const std::string &data){
    //1) ouvrir le fichier
    std::ifstream file(data);
    //2) checker si le fichier existe et qu il s'ouvre bien ->error
	if (!file)
		throw std::invalid_argument("invalid file");
	
    if (file.empty())
        throw std::invalid_argument("argument empty");

    //3) commencer à parser les infos : string + double -> si pas double ou negatif -> error
    parseDataToMap(file);
    file.close();
    //4) checker si dates sont valides -> sinon error avant 3 janvier 2009 pas possible pcq pas bitcoin

    // 5) dernier check de qqc ?
}

double BitcoinExchange::dataComp(const std::string &av){
    // ligne par ligne

    // verifier viabilité de la date -> error
    // string pour la date -> lowerbound() -- sur la string de la map -> sinon error

    // si pas de double -> error

    // faire le calcul et le renvoyer
}
