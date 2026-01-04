/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:49:53 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 21:04:15 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("undefined") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
		AForm::opertator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(const Bureaucrat& obj) const{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (obj.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
    std::string filename = "../" + _target + "_shrubbery"
    std::buffer = "          &&& &&  & &&\n      && &\/&\|& ()|/ @, &&\n      &\/(/&/&||/& /_/)_&/_&\n   &() &\/&|()|/&\/ '%` & ()\n  &_\_&&_\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\&\|&&-&&--%---()~\n     &&     \|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n"
    std::ofstream new_file(filename.c_str());
    new_file << buffer;
}



