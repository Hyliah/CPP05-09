/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:55:36 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 18:50:19 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

class Form;

class Bureaucrat {
	private :
		std::string	_name;
		int			_grade;

	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
        void signForm(Form& form) const;

		class GradeTooHighException : public std::exception {
			public : 
				virtual const char* what() const throw(){
					return ("Error : Grade too high");
				}
		};
		
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw(){
					return ("Error : Grade too low");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& object);

#endif