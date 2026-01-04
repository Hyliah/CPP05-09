/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:45:00 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 20:51:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises, then informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, it informs that the robotomy failed.

// All of them take only one parameter in their constructor: the target of the form. For
// example, "home" if you want to plant shrubbery at home.


#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private :
		std::string _target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void execute(const Bureaucrat& obj) const;
} ;

#endif