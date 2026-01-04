/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:55:53 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 18:50:31 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other){
	_grade = other._grade;
	_name = other._name;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other){
		_grade = other._grade;
		_name = other._name;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(){
}

std::string Bureaucrat::getName() const{
	return (_name);
}

int Bureaucrat::getGrade() const{
	return (_grade);
}

void Bureaucrat::incrementGrade(){
	_grade--;
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(){
	_grade++;
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) const{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object) {
	os << object.getName() << ", bureaucrat grade " << object.getGrade();
	return os;
}
