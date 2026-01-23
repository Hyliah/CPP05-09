/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DynCastFunc.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:51:45 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/23 16:10:05 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

// It randomly instantiates A, B, or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.
Base * generate(void);

//It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base* p);

// It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// inside this function is forbidden.
void identify(Base& p);