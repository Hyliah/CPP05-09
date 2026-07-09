/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmmList.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 23:32:53 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/09 01:59:44 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::list<int> PmergeMe::sortList(std::list<int> li) {
	size_t size = li.size();
	if (size <= 1)
		return li;

	bool hasPending = (li.size() % 2);
	int pending = 0;

	if (hasPending) {
		pending = li.back();
		li.pop_back();
	}

	std::list<std::pair<int, int> > pairs = makePairsList(li);

	std::list<int> big;
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		big.push_back(it->second);
	big = sortList(big);

	std::list<int> small = buildSmallList(big, pairs);

	std::list<int> mainChain;
	std::list<int>::iterator sit = small.begin();
	std::list<int>::iterator bit = big.begin();

	mainChain.push_back(*sit++);
	mainChain.push_back(*bit++);

	while (bit != big.end()) 
		mainChain.push_back(*bit++);

    insertJacobsthalList(mainChain, small, big);

	if (hasPending) {
		std::list<int>::iterator pos = lowerBoundList(mainChain.begin(), mainChain.end(), pending);
		mainChain.insert(pos, pending);
	}
	return mainChain;
}

std::list<std::pair<int, int> > PmergeMe::makePairsList(std::list<int>& li) {
	std::list<std::pair<int, int> > pairs;
	std::list<int>::iterator it = li.begin();

	while (it != li.end()) {
		int first = *it++;
		int second = *it++;

		if (first < second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}

	return pairs;
}

std::list<int> PmergeMe::buildSmallList(std::list<int>& big, std::list<std::pair<int, int> >& pairs) {
	std::list<int> small;

	for (std::list<int>::iterator bit = big.begin(); bit != big.end(); ++bit) {
		for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit) {
			if (pit->second == *bit) {
				small.push_back(pit->first);
				pairs.erase(pit);
				break;
			}
		}
	}
	return small;
}

void PmergeMe::insertJacobsthalList(std::list<int>& mainChain, std::list<int>& small, std::list<int>& big) {
	std::vector<size_t> order = jacobsthalIndexes(small.size());

    for (size_t k = 0; k < order.size(); ++k) {
		size_t idx = order[k];

		std::list<int>::iterator sIt = small.begin();
		std::advance(sIt, idx);

		std::list<int>::iterator bIt = big.begin();
		std::advance(bIt, idx);

		insertBeforePartnerList(mainChain, *sIt, *bIt);
	}
}

void PmergeMe::insertBeforePartnerList(std::list<int>& mainChain, int small, int large) {
	std::list<int>::iterator limit = std::find(mainChain.begin(), mainChain.end(), large);
	std::list<int>::iterator pos = lowerBoundList(mainChain.begin(), limit, small);

	mainChain.insert(pos, small);
}

std::list<int>::iterator PmergeMe::lowerBoundList(std::list<int>::iterator first, std::list<int>::iterator last, int value)
{
	if (first == last)
		return first;

    _listComparisons++;
	std::list<int>::iterator mid = first;
	std::list<int>::difference_type step = std::distance(first, last) / 2;

	std::advance(mid, step);

	if (*mid < value) {
		++mid;
		return lowerBoundList(mid, last, value);
	}

	return lowerBoundList(first, mid, value);
}

void PmergeMe::printList(std::ofstream& log, const std::list<int>& li) {
	std::list<int>::const_iterator it = li.begin();

	while (it != li.end()) {
		log << *it;
		std::list<int>::const_iterator next = it;
		++next;

		if (next != li.end())
			log << " ";
		++it;
	}
	log << std::endl;
}
