/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:55:53 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 01:12:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _Name("default"), _Grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name), _Grade(grade){
	if (_Grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_Grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	_Grade = other._Grade;
	_Name = other._Name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		_Grade = other._Grade;
		_Name = other._Name;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName() const{
	return (_Name);
}

int Bureaucrat::getGrade() const{
	return (_Grade);
}

void Bureaucrat::incrementGrade(){
	_Grade--;
	if (_Grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
	_Grade++;
	if (_Grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form){
	try {
		form::beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (exception &e){
		std::cout << _name " couldn’t sign " << form.getName() << " because " e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object) {
	os << object.getName() << ", bureaucrat grade " << object.getGrade();
	return os;
}
