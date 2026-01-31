/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 23:02:01 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/31 03:15:48 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include "Intern.hpp"

int main() {
    std::cout << "\n===== BIRTH OF THE INTERN =====\n\n";
    Intern someRandomIntern;
    std::cout << someRandomIntern << std::endl;

    std::cout << "\n===== BUREAUCRATS CREATION =====\n\n";
    Bureaucrat senior("Senior", 50);
    std::cout << senior << std::endl;
    Bureaucrat boss("Boss", 1);
    std::cout << boss << std::endl;

    std::cout << "\n===== INTERN CREATES FORMS =====\n\n";

    AForm* f1 = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    std::cout << *f1 << std::endl;
    std::cout << "---" << std::endl;
    AForm* f2 = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
    std::cout << *f2 << std::endl;
    std::cout << "---" << std::endl;
    AForm* f3 = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
    std::cout << *f3 << std::endl;
    std::cout << "---" << std::endl;
    AForm* f4 = someRandomIntern.makeForm("unknown form", "Nobody");

    std::cout << "\n===== TEST SIGNATURE ET EXECUTION =====\n";

    std::cout << "\n --- Form 1 --- \n"<< std::endl;
    if (f1) {
        senior.signForm(*f1);
        std::cout << "---" << std::endl;
        senior.executeForm(*f1);
        std::cout << "---" << std::endl;
        boss.executeForm(*f1);
    }

    std::cout << "\n --- Form 2 --- \n"<< std::endl;
    if (f2) {
        senior.signForm(*f2);
        std::cout << "---" << std::endl;
        boss.signForm(*f2);
        std::cout << "---" << std::endl;
        senior.executeForm(*f2);
        std::cout << "---" << std::endl;
        boss.executeForm(*f2);
    }

    std::cout << "\n --- Form 3 --- \n"<< std::endl;
    if (f3) {
        boss.signForm(*f3);
        std::cout << "---" << std::endl;
        boss.executeForm(*f3);
    }

    delete f1;
    delete f2;
    delete f3;
    delete f4; //? Y a t il besoin, voir avec Valgrind

    return 0;
}
