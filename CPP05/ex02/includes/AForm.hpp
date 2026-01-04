/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:38:51 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 17:43:47 by hlichten         ###   ########.fr       */
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
		vitrual ~AForm();

		int getExecGrade( void ) const;
		int getSignGrade( void ) const;
		bool getIsSigned( void ) const;
		std::string getName( void ) const;
		void beSigned(const Bureaucrat& obj);
	
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
} ;

std::ostream& operator<<(std::ostream& os, const AForm& object);

#endif