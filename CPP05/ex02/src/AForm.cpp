/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:41:21 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 17:41:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// ------- constructors and destructors --------

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150){
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec){
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade){
	_isSigned = other._isSigned;
}

// const atttributes can t be reasign
AForm& AForm::operator=(const AForm &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(){
}

// ---- getters -------

int AForm::getSignGrade( void ) const{
	return (_signGrade);
}

int AForm::getExecGrade( void ) const{
	return (_execGrade);
}

std::string AForm::getName( void ) const{
	return (_name);
}

bool AForm::getIsSigned( void ) const{
	return (_isSigned);
}


// ----- member functions ---------

void AForm::beSigned(const Bureaucrat& obj){
	if (obj.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

// -------- operator << ----------

std::ostream& operator<<(std::ostream& os, const AForm& f){
	os << "AForm " << f.getName() << " | signed: " << f.getIsSigned() << " | sign grade: " << f.getSignGrade() << " | exec grade: " << f.getExecGrade();
	return os;
}
