/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 23:56:38 by hlichten          #+#    #+#             */
/*   Updated: 2026/01/22 00:49:34 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include <cstdint>

int main()
{
    Data data;
    data.value = 42;

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << newPtr << std::endl;

    if (ptr == newPtr)
        std::cout << "Pointers are equal ✅" << std::endl;
    else
        std::cout << "Pointers are different ❌" << std::endl;

    return 0;
}

// Write a program to test that your class works as expected.

// You must create a non-empty (meaning it has data members) Data structure.
// Use serialize() on the address of the Data object and pass its return value to
// deserialize(). Then, ensure the return value of deserialize() compares equal to the
// original pointer.
// Do not forget to turn in the files of your Data structure