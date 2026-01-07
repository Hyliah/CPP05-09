/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:44:58 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 21:37:39 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("undefined") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

//change that
// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.

void RobotomyRequestForm::execute(const Bureaucrat& obj) const{
	if (obj.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
    std::cout << "🚧 Drilling Noises 🚧" << std::endl;
	std::cout << _target << " has been robotomized successfully 50% of the time." << std::endl; 
}
