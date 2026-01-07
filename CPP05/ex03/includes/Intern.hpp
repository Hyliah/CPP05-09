/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 21:41:03 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 23:19:03 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#ifndef INTERN_HPP
# define INTERN_HPP

class Intern {
	private :
	public :
		Intern();
		Intern(Intern& other);
		Intern& operator=(Intern& other);
		~Intern();

		AForm* makeForm(std::string name, std::string target);
} ;

std::ostream& operator<<(std::ostream& os, const Intern& object);

#endif