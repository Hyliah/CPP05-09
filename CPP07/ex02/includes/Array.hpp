/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 01:30:40 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/04 23:36:35 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
    private :
        T* _array;
        int _size;

    public :

        // CONSTRUCTORS AND DESTRUCTORS 
        Array() : _array(NULL), _size(0){}

        Array(int n) : _array(NULL), _size(n){
            if (n > 0)
                _array = new T[n]();
            std::cout << "[Array] Parametric constructor called snd _size = " << _size << std::endl;
        }

        Array(const Array& other): _array(NULL), _size(other._size){
            std::cout << "[Array] Copy constructor called (_size = " << _size << ")" << std::endl;
            if (_size > 0){
                _array = new T[_size]();
                for (int i = 0; i < _size ; i++)
                    _array[i] = other._array[i];
            }
        }
        
        Array& operator=(const Array& other){
            std::cout << "[Array] Assignment operator called" << std::endl;
            if (this != &other){
                std::cout << "        Assigning array of size " << other._size << " to array of size " << _size << std::endl;
                delete[] _array;
                _array = NULL;
                _size = other._size;

                if (_size > 0){
                    _array = new T[_size]();
                    for (int i = 0; i < _size ; i++)
                        _array[i] = other._array[i];
                }
            }
            return *this;
        }

        ~Array(){
            std::cout << "[Array] Destructor called" << std::endl;
            delete[] _array;
        }

        // MEMBER FUNCTIONS

        T& operator[](int i){
            if (i < 0 || i >= _size)
                throw indexOutOfBound();
            return _array[i];
        }

        const T& operator[](int i) const {
            if (i < 0 || i >= _size)
                throw indexOutOfBound();
            return _array[i];
        }
        int size( void ) const{
            return _size;
        }

        // 
        class indexOutOfBound : public std::exception {
            public : 
				virtual const char* what() const throw(){
                    return ("Error : Index is out of bounds");
            }
        };
};
#endif


// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:

// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.

// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.

// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.

// • A member function size() that returns the number of elements in the array. This
// member function takes no parameters and must not modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.