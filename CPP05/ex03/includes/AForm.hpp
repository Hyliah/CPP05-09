/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:38:51 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 21:34:40 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#ifndef AFORM_HPP
# define AFORM_HPP

// In all cases, the base class Form must be an abstract class and should therefore be
// renamed AForm. Keep in mind that the form’s attributes need to remain private and
// that they belong to the base class.

// Now, add the execute(Bureaucrat const & executor) const member function to
// the base form and implement a function to execute the form’s action in the concrete
// classes. You must check that the form is signed and that the grade of the bureaucrat 
// attempting to execute the form is high enough. Otherwise, throw an appropriate exception.


class AForm{
	private :
		const std::string _name;
		bool _isSigned; // is signed or not
		const int _signGrade; // minimum grade to be signed
		const int _execGrade; // minimum grade to be executed 

	public :
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

		int getExecGrade( void ) const;
		int getSignGrade( void ) const;
		bool getIsSigned( void ) const;
		std::string getName( void ) const;
		void beSigned(const Bureaucrat& obj);
        virtual void execute(const Bureaucrat& obj) const = 0;

	
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

        class FormNotSignedException : public std::exception {
			public :
				virtual const char* what() const throw(){
					return ("Error : Form not signed");
				}
		};

		class FormAlreadySignedException : public std::exception {
			public :
				virtual const char* what() const throw(){
					return ("Error : Form already signed");
				}
		};
} ;

std::ostream& operator<<(std::ostream& os, const AForm& object);

#endif