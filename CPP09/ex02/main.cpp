/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:09 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/08 23:49:44 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>

void parseInput(int ac, char **av, std::vector<int>& inputVector, std::list<int>& inputList);
void printVect(std::vector<int>& input);
void printList(std::list<int>& input);

int main (int ac, char **av){
	if (ac < 2){
		std::cerr << "nothing to sort" << std::endl;
		return 1;
	}
	std::vector<int> input;
	std::vector<int> inputVector;
	std::list<int> inputList;

	try {parseInput(ac, av, inputVector, inputList);}
	catch (std::exception &e) {std::cerr << e.what() << std::endl; return 1;}
	size_t size = inputVector.size();

	input = inputVector;
	PmergeMe pmm(inputVector, inputList);
	pmm.run();
	pmm.writeLog(input);
	
	std::cout << "Before: ";
	printVect(inputVector);
	std::cout << "After: ";
	printVect(pmm.getVector());

	std::cout << "Time to process a range of " << size << " elements with std::vector : " << pmm.getTimeVect() << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::list : " << pmm.getTimeList() << " us" << std::endl;
}

void printVect(std::vector<int>& input){
	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i];
		if (i != input.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void parseInput(int ac, char **av, std::vector<int>& inputVector, std::list<int>& inputList){
	int i = 1;

	while (i < ac) {
		char *end;
		
		long long nb = strtoll(av[i], &end, 10);
		if (*end != '\0')
			throw std::invalid_argument("Error");
		if (nb > INT_MAX || nb < 0)
			throw std::invalid_argument("Error");
		int value = static_cast<int>(nb);

        for (size_t j = 0; j < inputVector.size(); ++j) {
            if (inputVector[j] == value)
                throw std::invalid_argument("Error");
        }

        inputVector.push_back(value);
		inputList.push_back(value);
		i++;
	}
}
