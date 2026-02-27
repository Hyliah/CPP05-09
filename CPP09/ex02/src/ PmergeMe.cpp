/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:12 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/27 18:29:11 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other) : _li(other._li), _vect(other._vect){}
PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		_li = other._li;
		_vect = other._vect;
	}
	return *this;
}
PmergeMe::~PmergeMe(){}

