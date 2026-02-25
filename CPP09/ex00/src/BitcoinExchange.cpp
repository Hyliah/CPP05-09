/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:11 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/26 00:36:59 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <map>
#include <string>
#include <fstream>

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
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::size_t pos = line.find(',');
		// pas de ","
		if (pos == std::string::npos) 
			throw std::invalid_argument("Error: bad format.");

		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 1);

		if (date.empty() || valueStr.empty())
			throw std::invalid_argument("Error: bad format.");

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
	std::ifstream file(data.c_str());
	//2) checker si le fichier existe et qu il s'ouvre bien ->error
	if (!file)
		throw std::invalid_argument("Error: could not open file.");
	//3) commencer à parser les infos : string + double -> si pas double ou negatif -> error
	parseDataToMap(file);
	file.close();
	//4) checker si dates sont valides -> sinon error avant 3 janvier 2009 pas possible pcq pas bitcoin
	std::map<std::string, double>::iterator it;
	for (it = _data.begin(); it != _data.end(); ++it)
	{
		if (!checkData(it->first))
			throw std::invalid_argument("Error: Invalid data");
	}
}

bool BitcoinExchange::checkData(const std::string &date){
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	
	if (date < "2009-01-02") //mise en ligne du bitcoin -> techniquement le 3 mais y a un 2 dns data.csv et je veux pouvoir faire mon exercie. Peut etre que c etait le 2 au soir en amerique mais que a greenwich c etait le matin du 3 donc ils se sont dit, on va partir sur cette date je ne sais pas
		return false;
	
	int year  = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
	int month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
	if (month < 1 || month > 12)
		return false;
	int day   = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	if (day < 1)
		return false;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
		return false; // 31 jours
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false; // 30 jours
	if (month == 2) // fevrier et bisextile (melo coucou)
	{
		bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if ((leap && day > 29) || (!leap && day > 28))
			return false;
	}
	return true;
}

double BitcoinExchange::dataComp(const std::string &av){
	// ligne par ligne

	std::ifstream file(av.c_str());
	if (!file)
		throw std::invalid_argument("Error: could not open file.");

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line))
	{
		std::size_t pos = line.find('|'); //find ici est de std et pas la stl (begin, end, value)
		if (pos == std::string::npos){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pos - 1);
		std::string valueStr = line.substr(pos + 2);

		if (date.empty() || valueStr.empty()){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		char* end;
		double value = std::strtod(valueStr.c_str(), &end); //ne prendra que les caractères valide. met a jour end
		if (*end != '\0'){
			std::cout << "Error: bad input" << line << std::endl;
			continue;
		}

		if (line[10] != ' ' || line[12] != ' '){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!checkData(date)){
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value > 1000){
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (value < 0){
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		
		std::map<std::string, double>::iterator it = _data.lower_bound(date); //renvoie >= date
		if (it == _data.end()) // date > last date DB, du coup on prend la dernière date
			--it;
	
		else if (it->first != date) { // si pas exactement la date -> la précédente
			if (it != _data.begin())
				--it;
			else{
				std::cout << "Error: date too early => " << date << std::endl;
				continue;
			}
		}

		double rate = it->second;
		double result = rate * value;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	file.close();
	return (0);
}
