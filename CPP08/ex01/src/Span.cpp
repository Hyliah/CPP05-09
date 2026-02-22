/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:45:51 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/22 22:24:33 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _maxSize(N){}
Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize){}
Span& Span::operator=(const Span &other){
    if (this != &other){
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return (*this);
}
Span::~Span(){}

void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");

    _numbers.push_back(number);
}
unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Min 2 elements needed to find span");
    
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    unsigned int shortest = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++){
        unsigned int diff = (tmp[i] - tmp[i - 1]);
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Min 2 elements needed to find span");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    return static_cast<unsigned int>(tmp.back() - tmp.front());
}
// No problem with an int max -> unsigned int is 2 time bigger than an int. So if the diff is int_max - int_min : no issues