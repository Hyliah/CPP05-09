/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:12 by hlichten          #+#    #+#             */
/*   Updated: 2026/06/21 17:54:13 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(std::vector<int> vect, std::list<int> li) : _vect(vect), _li(li), _timeList(0), _timeVect(0){
	double start = getTimeMicro();
	_vect = sortVector(_vect);
	double end = getTimeMicro();
	_timeVect = end - start;
	
	start = getTimeMicro();
	sortList(_li);
	end = getTimeMicro();
	_timeList = end - start;
}
PmergeMe::PmergeMe(const PmergeMe &other) : _li(other._li), _vect(other._vect), _timeList(other._timeList), _timeVect(other._timeVect){}
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

//GETTERS 
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

// SORTING LIST
void PmergeMe::sortList(std::list<int> li){

}


// SORTING VECTOR
void printVect(std::vector<size_t>& input){
	for (size_t i = 0; i < input.size(); ++i)
	{
		std::cout << input[i];
		if (i != input.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

// std::vector<std::pair<int,int> > mergeSortPairs(std::vector<std::pair<int,int> >& vect)
//     {
//         if (vect.size() <= 1)
//             return vect;

//         size_t mid = vect.size() / 2;

//         std::vector<std::pair<int,int> > left(vect.begin(), vect.begin() + mid);
//         std::vector<std::pair<int,int> > right(vect.begin() + mid, vect.end());

//         left = mergeSortPairs(left);
//         right = mergeSortPairs(right);

//         std::vector<std::pair<int,int> > result;

//         size_t i = 0, j = 0;

//         while (i < left.size() && j < right.size())
//         {
//             if (left[i].second < right[j].second)
//                 result.push_back(left[i++]);
//             else
//                 result.push_back(right[j++]);
//         }

//         while (i < left.size())
//             result.push_back(left[i++]);

//         while (j < right.size())
//             result.push_back(right[j++]);

//         return result;
//     }

// void mergePairs(std::vector<std::pair<int, int> >& pairs, size_t left, size_t mid, size_t right) {
    
// 	std::vector<std::pair<int, int> > leftVect;
//     std::vector<std::pair<int, int> > rightVect;

//     for (size_t i = left; i <= mid; ++i)
//         leftVect.push_back(pairs[i]);

//     for (size_t i = mid + 1; i <= right; ++i)
//         rightVect.push_back(pairs[i]);

//     size_t i = 0;
//     size_t j = 0;
//     size_t k = left;

//     while (i < leftVect.size() && j < rightVect.size())
//     {
//         if (leftVect[i].second <= rightVect[j].second)
//             pairs[k++] = leftVect[i++];
//         else
//             pairs[k++] = rightVect[j++];
//     }

//     while (i < leftVect.size())
//         pairs[k++] = leftVect[i++];

//     while (j < rightVect.size())
//         pairs[k++] = rightVect[j++];
// }

// void mergeSortPairs(std::vector<std::pair<int, int> >& pairs, size_t left, size_t right) {
//     if (left < right) {
//         size_t mid = left + (right - left) / 2;
//         mergeSortPairs(pairs, left, mid);
//         mergeSortPairs(pairs, mid + 1, right);
//         mergePairs(pairs, left, mid, right);
//     }
// }
	
std::vector<int> PmergeMe::sortVector(std::vector<int> vect){
	size_t size = vect.size();
	if (size <= 1)
		return vect;

	// gestion impair 
	bool hasPending = (vect.size() % 2);
    int pending = 0;

	if (hasPending) {
        pending = vect.back();
        vect.pop_back();
    }
	
	// les pairs
	std::vector<std::pair<int,int> > pairs;
	for (size_t i = 0; i < vect.size(); i += 2) {
        if (vect[i] < vect[i + 1])
            pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
        else
            pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
    }

	// On extrait et sort les grands
    std::vector<int> big;
    for (size_t i = 0; i < pairs.size(); i++)
        big.push_back(pairs[i].second);
	big = sortVector(big);

	// Reconstruction des petit dans le nouvel ordre
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

	// construction de la mainChain a0 b0 b1 b2 b3 b4 etc...
	std::vector<int> mainChain;

	mainChain.push_back(small[0]);
    mainChain.push_back(big[0]);
	for (size_t i = 1; i < big.size(); i++)
        mainChain.push_back(big[i]);

	std::vector<size_t> order = jacobsthalIndexes(small.size());
	for (size_t k = 0; k < order.size(); ++k) {
		size_t idx = order[k];

		int sm = small[idx];
		int la = big[idx];

		//position de large (va chercher l index avec jacob) dans la main
		std::vector<int>::iterator limit = std::lower_bound(mainChain.begin(), mainChain.end(), la);
		//position de la ou on met le nb mais on cherche que jusqu a limit
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), limit, sm);

		//insertion dans la main a cet endroit 
		mainChain.insert(pos, sm);
	}


	if (hasPending) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending);
		mainChain.insert(pos, pending);
	}
	return mainChain;
}

double PmergeMe::getTimeMicro()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}


std::vector<size_t> PmergeMe::jacobsthalIndexes(size_t n) {    
	
	std::vector<size_t> order;
	std::vector<size_t> jac;
    if (n <= 1)
        return order;

    //Le jacobstahl de base
    jac.push_back(1);
    jac.push_back(3);
    while (jac.back() < n)
    {
        size_t sz = jac.size();
        jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
    }

    // Jacob inversés
    order.push_back(1);
    size_t prev_jac = 1;

    for (size_t k = 1; k < jac.size(); ++k)
    {
        size_t current_jac = jac[k];
        size_t end = (current_jac < n) ? current_jac : n - 1;

        for (size_t i = end; i > prev_jac; --i){
            order.push_back(i);
        }

        prev_jac = current_jac;
        if (prev_jac >= n - 1)
            break;
    }

    return order;
}
















// void mergePairs(std::vector<std::pair<int, int> >& pairs, size_t left, size_t mid, size_t right) {
    
// 	std::vector<std::pair<int, int> > leftVect;
//     std::vector<std::pair<int, int> > rightVect;

//     for (size_t i = left; i <= mid; ++i)
//         leftVect.push_back(pairs[i]);

//     for (size_t i = mid + 1; i <= right; ++i)
//         rightVect.push_back(pairs[i]);

//     size_t i = 0;
//     size_t j = 0;
//     size_t k = left;

//     while (i < leftVect.size() && j < rightVect.size())
//     {
//         if (leftVect[i].second <= rightVect[j].second)
//             pairs[k++] = leftVect[i++];
//         else
//             pairs[k++] = rightVect[j++];
//     }

//     while (i < leftVect.size())
//         pairs[k++] = leftVect[i++];

//     while (j < rightVect.size())
//         pairs[k++] = rightVect[j++];
// }

// void mergeSortPairs(std::vector<std::pair<int, int> >& pairs, size_t left, size_t right) {
//     if (left < right) {
//         size_t mid = left + (right - left) / 2;
//         mergeSortPairs(pairs, left, mid);
//         mergeSortPairs(pairs, mid + 1, right);
//         mergePairs(pairs, left, mid, right);
//     }
// }
	
// void PmergeMe::sortVector(std::vector<int>& vect){
// 	size_t size = vect.size();
// 	if (size <= 1)
// 		return;

// 	std::vector<std::pair<int,int> > pairs;
// 	std::vector<int> mainChain;

// 	bool hasPending = false;
//     int pending = 0;

// 	//mise en place dans les pairs PETIT/GRAND
// 	size_t i = 0; // pour garder le i si y aura un élément restant
// 	for (; i + 1 < vect.size(); i += 2) {
// 		if (vect[i] < vect[i + 1])
// 			pairs.push_back(std::make_pair(vect[i], vect[i + 1]));
// 		else
// 			pairs.push_back(std::make_pair(vect[i + 1], vect[i]));
// 	}

// 	//si impair, on met dans le pending
// 	if (i < vect.size()) {
//         hasPending = true;
//         pending = vect[i];
//     }

// 	if (!pairs.empty()) {
//     	mergeSortPairs(pairs, 0, pairs.size() - 1);
// 	}

// 	if (!pairs.empty())
//             mainChain.push_back(pairs[0].first); // first small

// 	//remplir la main chain avec les GRANDS
//     for (size_t k = 0; k < pairs.size(); ++k)
//             mainChain.push_back(pairs[k].second);

// 	std::vector<size_t> order = jacobsthalIndexes(pairs.size());
	
// 	for (size_t k = 0; k < order.size(); ++k) {
// 		size_t idx = order[k];

// 		int small = pairs[idx].first;
// 		int large = pairs[idx].second;

// 		//position de large (va chercher l index avec jacob) dans la main
// 		std::vector<int>::iterator limit = std::lower_bound(mainChain.begin(), mainChain.end(), large);
// 		//position de la ou on met le nb mais on cherche que jusqu a limit
// 		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), limit, small);

// 		//insertion dans la main a cet endroit 
// 		mainChain.insert(pos, small);
// 	}

//     if (hasPending) {
// 		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending);
// 		mainChain.insert(pos, pending);
// 	}
// 	vect = mainChain;
// }