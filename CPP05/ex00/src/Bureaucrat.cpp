/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 04:01:39 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/31 02:50:20 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	if ((_Grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	_Grade--;
}

void Bureaucrat::decrementGrade(){
	if ((_Grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	_Grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object) {
    os << object.getName() << ", bureaucrat grade " << object.getGrade();
    return os;
}
