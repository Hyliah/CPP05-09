/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:12 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/11 13:11:53 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(std::vector<int> vect, std::list<int> li) :  _li(li), _vect(vect), _timeList(0), _timeVect(0), _vectComparisons(0), _listComparisons(0) {}
PmergeMe::PmergeMe(const PmergeMe &other) : _li(other._li), _vect(other._vect), _timeList(other._timeList), _timeVect(other._timeVect), _vectComparisons(other._vectComparisons), _listComparisons(other._listComparisons) {}
PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this != &other){
		_li = other._li;
		_vect = other._vect;
		_timeList = other._timeList;
		_timeVect = other._timeVect;
	}
	return *this;
}
PmergeMe::~PmergeMe(){}

double PmergeMe::getTimeVect(){
	return (_timeVect);
}
double PmergeMe::getTimeList(){
	return (_timeList);
}
std::vector<int>& PmergeMe::getVector(){
	return (_vect);
}
std::list<int>& PmergeMe::getList(){
	return (_li);
}

void PmergeMe::run() {
	double start = getTimeMicro();
	_vect = sortVector(_vect);
	double end = getTimeMicro();
	_timeVect = end - start;
	
	start = getTimeMicro();
	_li = sortList(_li);
	end = getTimeMicro();
	_timeList = end - start;
}
