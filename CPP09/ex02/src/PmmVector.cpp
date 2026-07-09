/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmmVector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:34:05 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/09 01:58:09 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::sortVector(std::vector<int> vect){
	size_t size = vect.size();
	if (size <= 1)
		return vect;

	bool hasPending = (vect.size() % 2);
	int pending = 0;

	if (hasPending) {
		pending = vect.back();
		vect.pop_back();
	}

	std::vector<std::pair<int,int> > pairs = makePairsVector(vect);

	std::vector<int> big;
	for (size_t i = 0; i < pairs.size(); i++)
		big.push_back(pairs[i].second);
	big = sortVector(big);

	std::vector<int> small = buildSmallVector(big, pairs);
	std::vector<int> mainChain;

	mainChain.push_back(small[0]);
	mainChain.push_back(big[0]);
	for (size_t i = 1; i < big.size(); i++) 
		mainChain.push_back(big[i]);

    insertJacobsthalVector(mainChain, small, big);

	if (hasPending) {
		std::vector<int>::iterator pos = lowerBoundVector(mainChain.begin(), mainChain.end(), pending);
		mainChain.insert(pos, pending);
	}
	return mainChain;
}

std::vector<std::pair<int, int> > PmergeMe::makePairsVector(std::vector<int>& vect) {
	std::vector<std::pair<int, int> > pairs;

	for (size_t i = 0; i < vect.size(); i += 2) {
		if (vect[i] < vect[i + 1])
			pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
		else
			pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
	}

	return pairs;
}

void PmergeMe::insertBeforePartnerVect(std::vector<int>& mainChain, int small, int large) {
	std::vector<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), large);
	std::vector<int>::iterator pos = lowerBoundVector(mainChain.begin(), limit, small);

	mainChain.insert(pos, small);
}

std::vector<int> PmergeMe::buildSmallVector(std::vector<int>& big, std::vector<std::pair<int, int> >& pairs) {
    std::vector<int> small;
    
    for (size_t i = 0; i < big.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].second == big[i]) {
				small.push_back(pairs[j].first);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
    return small;
}

void PmergeMe::insertJacobsthalVector(std::vector<int>& mainChain, std::vector<int>& small, std::vector<int>& big){
    std::vector<size_t> order = jacobsthalIndexes(small.size());
	for (size_t k = 0; k < order.size(); ++k) {
		size_t idx = order[k];
		int sm = small[idx];
		int la = big[idx];

		insertBeforePartnerVect(mainChain, small[idx], big[idx] );
	}
}

std::vector<int>::iterator PmergeMe::lowerBoundVector(std::vector<int>::iterator first, std::vector<int>::iterator last, int value) {
    if (first >= last)
        return first;

    std::vector<int>::iterator mid = first + (last - first) / 2;
    _vectComparisons++;

    if (*mid < value)
        return lowerBoundVector(mid + 1, last, value);
    else
        return lowerBoundVector(first, mid, value);
}

void PmergeMe::printVector(std::ofstream& log, const std::vector<int>& vect) {
	for (size_t i = 0; i < vect.size(); ++i) {
		log << vect[i];

		if (i != vect.size() - 1)
			log << " ";
	}
	log << std::endl;
}
