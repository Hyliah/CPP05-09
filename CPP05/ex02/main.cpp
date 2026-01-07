/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:16:49 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 21:38:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::cout << "===== BUREAUCRATS CREATION =====" << std::endl;

	Bureaucrat boss("Boss", 1);
	Bureaucrat senior("Senior", 50);
	Bureaucrat junior("Junior", 150);

	std::cout << boss << std::endl;
	std::cout << senior << std::endl;
	std::cout << junior << std::endl;
	
	std::cout << std::endl;

	std::cout << "===== FORMS CREATION =====" << std::endl;

	AForm* shrub = new ShrubberyCreationForm("home");
	AForm* robot = new RobotomyRequestForm("Bender");
	AForm* pardon = new PresidentialPardonForm("Arthur Dent");

	std::cout << *shrub << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *pardon << std::endl;

	std::cout << std::endl;

	std::cout << "===== JUNIOR TRIES TO SIGN =====" << std::endl;

	junior.signForm(*shrub);
	junior.signForm(*robot);
	junior.signForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== SENIOR SIGN AND EXECUTE SOME STUFF =====" << std::endl;

	senior.signForm(*shrub);
	senior.executeForm(*shrub);
	std::cout << "---" << std::endl;
	senior.signForm(*robot);
	senior.executeForm(*robot);
	std::cout << "---" << std::endl;
	senior.signForm(*pardon);
	senior.executeForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== SIGNED BY THE BOSS =====" << std::endl;

	boss.signForm(*shrub);
	boss.signForm(*robot);
	boss.signForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== INTERN TRIES TO EXECUTE =====" << std::endl;

	junior.executeForm(*shrub);
	junior.executeForm(*robot);
	junior.executeForm(*pardon);

	std::cout << std::endl;

	std::cout << "===== BOSS EXECUTE THE REST =====" << std::endl;

	boss.executeForm(*robot);
	std::cout << "---" << std::endl;
	boss.executeForm(*pardon);

	std::cout << std::endl;

	delete shrub;
	delete robot;
	delete pardon;

	return 0;
}
