/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 04:01:44 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/01 22:34:15 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Bureaucrat {
	private :
		std::string _Name;
		std::string _Grade;

	public :
		std::string getName();
		std::string getGrade();

	class GradeTooHighException : public std::exception {
		//thow = 0
	};
};

//voir les videos

//en parametre : os stream & instance de classe 
std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);

//classes
//a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException

#endif