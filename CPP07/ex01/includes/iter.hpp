/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:16:47 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/03 03:09:32 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ITER_HPP
# define ITER_HPP

// 2 functions for the const and non const
// array and functions are generic to accept a variaty of types. 
// length can t be generic so -> size_t bc it has to be an "entier" cant be negative and must accept a large number -> size_t

template <typename T, typename F>
void iter(T* array, const size_t length, F function){
    for (size_t i = 0 ; i < length; i++){
        function(array[i]);
    }
}

template <typename T, typename F>
void iter(const T* array, const size_t length, const F function){
    for (size_t i = 0 ; i < length; i++){
    function(array[i]);
    }
}


// TEST MAIN FUNCTIONS :

void increment(int& x) {
    x++;
}

template <typename T>
void print(const T& x) {
    std::cout << x << " ";
}

#endif


// Implement a function template iter that takes 3 parameters and returns nothing.

// • The first parameter is the address of an array.
// • The second one is the length of the array, passed as a const value.
// • The third one is a function that will be called on every element of the array.

// Submit a main.cpp file that contains your tests. Provide enough code to generate a
// test executable.

// Your iter function template must work with any type of array. The third parameter
// can be an instantiated function template.

// The function passed as the third parameter may take its argument by const reference
// or non-const reference, depending on the context.
// Think carefully about how to support both const and non-const
// elements in your iter function.