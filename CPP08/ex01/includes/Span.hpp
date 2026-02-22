/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 22:17:25 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/22 21:10:07 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

class Span{
    private : 
        std::vector<int> _numbers;
        unsigned int _maxSize;

    public :
        Span(unsigned int N);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span();

        void addNumber(int N);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
};