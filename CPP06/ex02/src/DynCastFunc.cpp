/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DynCastFunc.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:53:40 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/23 16:13:28 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DynCastFunc.hpp"

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
		
void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}
		
void identify(Base& p){

	try {
        A& a = dynamic_cast<A&>(p); // if error -> catched 
        (void)a; //avoid warning
        std::cout << "A" << std::endl; // if no error -> print and leave
        return;
	}
	catch (...) {} //in this case we could use std::bad_cast

	try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
	}
	catch (...) {}

	try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
	}
	catch (...) {}
}