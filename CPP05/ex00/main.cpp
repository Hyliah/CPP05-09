/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:53:14 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/29 16:23:24 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// try and catch in the main -> end the program if there s a catch
int main(){

	// ---------- TOO LOW in initialization -------

	// try {
	// 	Bureaucrat Elise("Elise", 42);
	// 	std::cout << Elise << std::endl;
	// 	Bureaucrat Bob("Bob", 175);
	// 	std::cout << Bob << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// --------- TOO HIGH in initlialization --------

	// try {
	// 	Bureaucrat Elise("Elise", 42);
	// 	std::cout << Elise << std::endl;
	// 	Bureaucrat Bob("Bob", 0);
	// 	std::cout << Bob << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// ----------- TOO HIGH because of an incrementation ---- 

	// try {
	// 	Bureaucrat Gertrude("Gertrude", 2);
	// 	std::cout << Gertrude << std::endl;
	// 	Gertrude.incrementGrade();
	// 	std::cout << Gertrude << std::endl;
	// 	Gertrude.incrementGrade();
	// 	std::cout << Gertrude << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }

	// --------- TOO LOW because of a decrementation ---------

	try {
		Bureaucrat John("John", 139);
		std::cout << John << std::endl;

		for (int i = 0; i < 40 ; i++){
			John.decrementGrade();
			std::cout << John << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
