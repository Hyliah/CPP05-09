/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:45:09 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 23:24:18 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
}

Intern::Intern(Intern& other){
	(void)other;
}

Intern& Intern::operator=(Intern& other){
	(void)other;
	return (*this);
}

Intern::~Intern(){
}

AForm* robotomy(std::string name){
	return (new RobotomyRequestForm(name));
}

AForm* presidential(std::string name){
	return (new PresidentialPardonForm(name));
}

AForm* shrubbery(std::string name){
	return (new ShrubberyCreationForm(name));
}

AForm* Intern::makeForm(std::string formName, std::string target){
	static const char *tab[3] = {"shrubbery", "robotomy", "presidential"};
	AForm* (*p[3])(std::string) = {shrubbery, robotomy, presidential};
	
	std::string lowName = formName;
	std::transform(lowName.begin(), lowName.end(), lowName.begin(), ::tolower);
	
	for (int i = 0; i < 3 ; i++){
		if (lowName.find(tab[i]) != std::string::npos){
			std::cout << "Intern creates " << formName << std::endl;
			return (p[i](target));
		}
	}

	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}

std::ostream& operator<<(std::ostream& os, const Intern& f){
	(void)f;
	os << "unamed, complitly transparent and underpaid intern exists, I mean work is done somehow";
	return os;
}