/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:16:52 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/22 20:32:19 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base{
	public :
		virtual ~Base();
		
		Base * generate(void);
		// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
		// to use anything you like for the random choice implementation.
		
		void identify(Base* p);
		//It prints the actual type of the object pointed to by p: "A", "B", or "C".
		
		void identify(Base& p);
		// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
		// inside this function is forbidden.
};

//Implement a Base class that has a public virtual destructor only. 
#endif