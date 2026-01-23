/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DynCastFunc.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:53:40 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/23 16:10:10 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DynCastFunc.hpp"

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * generate(void){
	int r = std::rand() % 3 + 1;
	switch (r)
	{
	case 1:
        std::cout << "Base A generated" << std::endl; //non asked by subject, intended to showcase how the program works
		return (new A());
	case 2:
        std::cout << "Base B generated" << std::endl; //non asked by subject, intended to showcase how the program works
		return (new B());
	default:
        std::cout << "Base C generated" << std::endl; //non asked by subject, intended to showcase how the program works
		return (new C());
	}
}
		
//It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}
		
// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p){

	try {
        A& a = dynamic_cast<A&>(p); // if error -> catched 
        (void)a; //avoid warning
        std::cout << "A" << std::endl; // if no error -> print and leave
        return;
	}
	catch (...) {} //in this case we could use std::bad_cast

	try {
        B& b = dynamic_cast<B&>(p); // if error -> catched 
        (void)b; //avoid warning
        std::cout << "B" << std::endl; // if no error -> print and leave
        return;
	}
	catch (...) {}

	try {
        C& c = dynamic_cast<C&>(p); // if error -> catched 
        (void)c; //avoid warning
        std::cout << "C" << std::endl; // if no error -> print and leave
        return;
	}
	catch (...) {}
}