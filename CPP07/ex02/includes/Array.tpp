/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 00:17:29 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/05 00:34:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array(int n) : _array(NULL), _size(n){
	if (n > 0)
		_array = new T[n]();
	std::cout << "[Array] Parametric constructor called snd _size = " << _size << std::endl;
}

template <typename T>
Array<T>::Array(const Array& other): _array(NULL), _size(other._size){
	std::cout << "[Array] Copy constructor called (_size = " << _size << ")" << std::endl;
	if (_size > 0){
		_array = new T[_size]();
		for (int i = 0; i < _size ; i++)
			_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
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

template <typename T>
Array<T>::~Array(){
	std::cout << "[Array] Destructor called" << std::endl;
	delete[] _array;
}

// MEMBER FUNCTIONS

template <typename T>
T& Array<T>::operator[](int i){
	if (i < 0 || i >= _size)
		throw indexOutOfBound();
	return _array[i];
}

template <typename T>
const T& Array<T>::operator[](int i) const {
	if (i < 0 || i >= _size)
		throw indexOutOfBound();
	return _array[i];
}

template <typename T>
int Array<T>::size( void ) const{
	return _size;
}