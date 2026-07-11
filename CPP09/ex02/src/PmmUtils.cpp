/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmmUtils.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:38:56 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/11 13:14:30 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::jacobsthalIndexes(size_t n) {    
	std::vector<size_t> order;
	std::vector<size_t> jac;
	if (n <= 1)
		return order;

	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < n) {
		size_t sz = jac.size();
		jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
	}

	order.push_back(1);
	size_t prev_jac = 1;

	for (size_t k = 1; k < jac.size(); ++k) {
		size_t current_jac = jac[k];
		size_t end;
		if (current_jac < n)
			end = current_jac;
		else
			end = n - 1;
			
		for (size_t i = end; i > prev_jac; --i) {
			order.push_back(i);
		}
		prev_jac = current_jac;
		if (prev_jac >= n - 1)
			break;
	}
	return order;
}

double PmergeMe::getTimeMicro() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

size_t PmergeMe::fordJohnsonComparisons(size_t n) {
    size_t  res = 0;
    double  value;

    for (size_t k = 1; k <= n; ++k) {
        value = (3.0 / 4.0) * k;
        res += static_cast<size_t>(ceil(log2(value)));
    }
    return (res);
}

bool PmergeMe::isSortedVector(const std::vector<int>& vect) {
	if (vect.size() <= 1)
		return true;

	for (size_t i = 1; i < vect.size(); i++) {
		if (vect[i - 1] > vect[i])
			return false;
	}
	return true;
} 

bool PmergeMe::sameSizeVector( const std::vector<int>& input, const std::vector<int>& output) {
	return input.size() == output.size();
}

bool PmergeMe::isSortedList(const std::list<int>& li) {
	if (li.size() <= 1)
		return true;

	std::list<int>::const_iterator prev = li.begin();
	std::list<int>::const_iterator current = prev;
	++current;

	while (current != li.end()) {
		if (*prev > *current)
			return false;
		++prev;
		++current;
	}
	return true;
}

bool PmergeMe::sameSizeList( const std::vector<int>& input, const std::list<int>& output) {
	return input.size() == output.size();
}


void PmergeMe::writeLog(const std::vector<int>& input){
	std::ofstream log("log.txt");

	if (!log.is_open())
		return ;

	log << "\nBEFORE" << std::endl;
	printVector(log, input);

	log << "\nAFTER" << std::endl;
	log << "Vector :" << std::endl;
	printVector(log, _vect);

	log << "List :" << std::endl;
	printList(log, _li);

	log << "\nTIMES" << std::endl;
	log << "Vector : " << _timeVect << " us" << std::endl;
	log << "List   : " << _timeList << " us" << std::endl;

	log << "\nSTATISTICS" << std::endl;
	log << "Vector Comparisons : " << _vectComparisons << std::endl;
	log << "List Comparisons : " << _listComparisons << std::endl;
	log << "Ford Johnson comparisons for " << _vect.size() << " : " << fordJohnsonComparisons(_vect.size()) << std::endl;

    log << "\nTESTS" << std::endl;
    if (isSortedVector(_vect)) log << "Vector is nicely sorted" << std::endl;
    else log << "Issues with the vector's sorting" << std::endl;

    if (isSortedList(_li)) log << "List is nicely sorted" << std::endl;
    else log << "Issues with the list's sorting" << std::endl;
    
    if (sameSizeVector(input, _vect)) log << "Vector has the same size as the input" << std::endl;
    else log << "Vector is not the same size as the input" << std::endl;
	
    if (sameSizeList(input, _li)) log << "List has the same size as the input" << std::endl;
    else log << "List is not the same size as the input" << std::endl;
    
    log.close();
}