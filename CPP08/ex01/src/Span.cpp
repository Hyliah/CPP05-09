/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:45:51 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/20 02:12:59 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N){}
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers){}
Span& Span::operator=(const Span &other){
    if (this != other){
        _maxSize = other._maxSize;
        _numbers = other._numbers
    return (*this);
    }
}
Span::~Span(){}

void Span::addNumber(int N){

}
unsigned int Span::shortestSpan() const {

}
unsigned int Span::longestSpan() const {

}