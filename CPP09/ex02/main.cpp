/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:09 by hlichten          #+#    #+#             */
/*   Updated: 2026/03/01 19:40:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " PmergeMe.hpp"
#include <cstdlib>

void parseInput(int ac, char **av, std::vector<int>& input);
void printVect(std::vector<int>& input);

int main (int ac, char **av){
	
	if (ac < 2){
		std::cerr << "nothing to sort" << std::endl;
		return 1;
	}

	PmergeMe pmm;

	// mettre la liste dans un vector temporaire. faire les verif au fur et a mesure (int, entre 0 et int max, pas de doublons)
	std::vector<int> input;
	try { parseInput(ac, av, input);}
	catch (std::exception &e) {std::cerr << e.what() << std::endl;}

	// afficher la liste avant le début des travaux. La sauver dans un vector a cahque verif. Si verif good on print
	// Before: 3 5 9 7 4
	std::cout << "Before: ";
	printVect(input);

	// faire les 2 sorting
	//		faire un tree avec les plus grand et insert les plus petits par la suite
	// print un des sorting
	// After: 3 4 5 7 9
	// afficher temps 1
	//.        Time to process a range of 5 elements with std::list : 0.00031 us
	// afficher temps 2
	//.        Time to process a range of 5 elements with std::vector : 0.00014 us


	// idée de boucle recursive : 
	/*
		void sortRec()
	*/
	try {

	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
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

void parseInput(int ac, char **av, std::vector<int>& input){
	int i = 1;

	while (i < ac){
		char *end;
		
		long long nb = strtoll(av[i], &end, 10);
		if (*end != '\0')
			throw std::invalid_argument("Error");
		if (nb > INT_MAX || nb < 0)
			throw std::invalid_argument("Error");
		int value = static_cast<int>(nb);

		//veriicateur de doublons
        for (size_t j = 0; j < input.size(); ++j)
        {
            if (input[j] == value)
                throw std::invalid_argument("Error");
        }

        input.push_back(value);
		i++;
	}
}

/*
	diviser en 2 int un gros et un petit, trier les gros et laisser chill les petits
	comprendre mieux le projet
	faire le projet 
	voila c est tout pour moi 
*/
/*

You must create a program with these constraints:
	• The name of the program is PmergeMe.
	• Your program must be able to use a positive integer sequence as an argument.
	• Your program must use the merge-insert sort algorithm to sort the positive integer sequence.

To clarify, yes, you need to use the Ford-Johnson algorithm.
(source: Art Of Computer Programming, Vol.3. Merge Insertion,
Page 184.)

• If an error occurs during program execution, an error message should be displayed
on the standard error.
You must use at least two different containers in your code to
validate this exercise. Your program must be able to handle at
least 3000 different integers.


It is strongly advised to implement your algorithm for each container
and thus to avoid using a generic function.

Here are some additional guidelines on the information you should display line by line
on the standard output:
	• On the first line you must display an explicit text followed by the unsorted positive
	integer sequence.
	• On the second line you must display an explicit text followed by the sorted positive
	integer sequence.
	• On the third line, you must display an explicit message indicating the time taken
	by your algorithm, specifying the first container used to sort the positive integer
	sequence.
	• On the last line you must display an explicit text indicating the time used by
	your algorithm by specifying the second container used to sort the positive integer
	sequence.

The format for the display of the time used to carry out your sorting
is free but the precision chosen must allow to clearly see the
difference between the two containers used.
Here is an example of standard use:

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us

$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us

$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>
The indication of the time is deliberately strange in this example.
Of course you have to indicate the time used to perform all your
operations, both the sorting part and the data management part.


Warning: The container(s) you used in the previous exercises are
forbidden here.

The management of errors related to duplicates is left to your
discretion.
*/