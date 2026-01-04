/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 20:56:13 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 00:09:26 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

class Bureaucrat;

#ifndef FORM_HPP
# define FORM_HPP

class Form{
	private :
		const std::string _name;
		bool _isSigned; // is signed or not
		const int _signGrade; // minimum grade to be signed
		const int _execGrade; // minimum grade to be executed 

	public :
		Form();
		Form(std::string name, int sign, int exec);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		int getSign( void ) const;
		int getGrade( void ) const;
		bool getSigned( void ) const;
		std::string getName( void ) const;
		void beSigned(Bureaucrat& obj);
	
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

std::ostream& operator<<(std::ostream& os, const Form& object);

#endif