/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 21:29:22 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 01:17:46 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// ------- constructors and destructors --------

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _execGrade(150){
}

Form::Form(std::string name, int sign, int exec) : _name(name), _isSigned(false), _signGrade(sign), _execGrade(exec){
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _signGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade){
	_isSigned = other._isSigned;
}

Form& Form::operator=(const Form &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(){
}

// ---- getters -------

int Form::getSign( void ) const{
	return (_signGrade);
}

int Form::getGrade( void ) const{
	return (_execGrade);
}

std::string Form::getName( void ) const{
	return (_name);
}

bool Form::getSigned( void ) const{
	return (_isSigned);
}


// ----- member functions ---------

void Form::beSigned(Bureaucrat& obj){
	if (obj.getGrade() > _signGrade)
		throw Form::GradeTooLowException;
	_isSigned = true;
}
// beSigned() member function to the Form that takes a Bureaucrat as a
// parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
// (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.

// -------- operator << ----------

std::ostream& operator<<(std::ostream& os, const Form& object){
	os << object.getGrade() << object.getName() << object.getSign();
}
