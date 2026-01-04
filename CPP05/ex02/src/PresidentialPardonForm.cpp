/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:10:49 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 20:52:12 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("undefined") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
		AForm::opertator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(const Bureaucrat& obj) const{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (obj.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}
