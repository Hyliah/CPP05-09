/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:19:27 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/07 21:17:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	
	std::cout << "===== BUREAUCRATS CREATION =====" << std::endl;
	Bureaucrat Junior("Junior", 148);
	Bureaucrat Senior("Senior", 56);
	Bureaucrat Boss("Boss", 1);
	std::cout << Junior << std::endl;
	std::cout << Senior << std::endl;
	std::cout << Boss << std::endl;
	std::cout << std::endl;

	std::cout << "===== FORM FormB42 CREATION =====" << std::endl;
	Form FormB42("FormB42", 55, 55);
	std::cout << FormB42 << std::endl;
	std::cout << std::endl;

	std::cout << "===== TRY TO SIGN BUT FAIL =====" << std::endl;
	Junior.signForm(FormB42);
	Senior.signForm(FormB42);
	std::cout << std::endl;

	std::cout << "===== SUCCESSFULLY SIGNED =====" << std::endl;
	Boss.signForm(FormB42);
	std::cout << std::endl;
}