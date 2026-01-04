/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:44:52 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 20:53:09 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  ShrubberyCreationForm: Required grades: sign 145, exec 137
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.

// All of them take only one parameter in their constructor: the target of the form. For
// example, "home" if you want to plant shrubbery at home.

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private :
		std::string _target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void execute(const Bureaucrat& obj) const;
} ;

#endif