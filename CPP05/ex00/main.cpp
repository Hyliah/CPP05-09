/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 21:53:14 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/02 22:09:57 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		Bureaucrat Nicolas("Nicolas", 139);
		std::cout << Nicolas << std::endl;

		for (int i = 0; i < 40 ; i++){
			Nicolas.decrementGrade();
			std::cout << Nicolas << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}