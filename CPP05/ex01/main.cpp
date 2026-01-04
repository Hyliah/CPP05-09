/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 01:19:27 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/04 01:29:19 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat Elise("Elise", 42);
    Form B132("48b", 55, 55);
    Elise.signForm(B132);

    Bureaucrat Nicolas("Nicolas", 148);
    Form B234("47b", 55, 55);
    Nicolas.signForm(B234);
}