/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:49:53 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 21:37:43 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("undefined") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(const Bureaucrat& obj) const{
	if (obj.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	std::string filename = _target + "_shrubbery";
	std::string buffer =
	"          /\\          \n"
	"         /**\\         \n"
	"        /****\\        \n"
	"       /******\\       \n"
	"      /********\\      \n"
	"     /**********\\     \n"
	"    /************\\    \n"
	"         |||          \n"
	"         |||          \n"
	"         |||          \n";

	std::ofstream new_file(filename.c_str());

	if (!new_file.is_open()){
		std::cerr << "Error : Failed to create file" << std::endl;
		return ;
	}
	new_file << buffer;
	new_file.close();
}
