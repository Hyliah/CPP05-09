/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:18:30 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/23 01:56:39 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

virtual Base::~Base(){
}

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * Base::generate(void){
	int r = std::rand() % 3 + 1;
	switch (r)
	{
	case 1:
		return (new A());
	case 2:
		return (new B());
	default:
		return (new C());
	}
}
		
//It prints the actual type of the object pointed to by p: "A", "B", or "C".
void Base::identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}
		
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.

// faire un try and catch 
void Base::identify(Base& p){
	if (dynamic_cast<A&>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B&>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C&>(p))
		std::cout << "C" << std::endl;
}
