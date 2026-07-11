/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:15 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/11 13:10:57 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>
#include <utility>
#include <cstddef>
#include <cmath>


class PmergeMe{
	private :
		std::list<int> _li;
		std::vector<int> _vect;
		double  _timeList;
		double  _timeVect;

	public:
		PmergeMe();
		PmergeMe(std::vector<int> vect, std::list<int> li);
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		~PmergeMe();
		
		double getTimeMicro();
		double getTimeVect();
		double getTimeList();

		void run();
		std::vector<int>& getVector();
		std::list<int>& getList();

		std::vector<size_t> jacobsthalIndexes(size_t n);

		std::list<int> sortList(std::list<int> li);
		std::vector<int> sortVector(std::vector<int> vect);

		std::list<std::pair<int, int> > makePairsList(std::list<int>& li);
		std::vector<std::pair<int, int> > makePairsVector(std::vector<int>& vect);
		std::list<int> buildSmallList(std::list<int>& big, std::list<std::pair<int, int> >& pairs);
		std::vector<int> buildSmallVector(std::vector<int>& big, std::vector<std::pair<int, int> >& pairs);
		void insertJacobsthalList(std::list<int>& mainChain, std::list<int>& small, std::list<int>& big);
		void insertJacobsthalVector(std::vector<int>& mainChain, std::vector<int>& small, std::vector<int>& big);
		void insertBeforePartnerVect(std::vector<int>& mainChain, int small, int large);
		void insertBeforePartnerList(std::list<int>& mainChain, int small, int large);
		std::vector<int>::iterator lowerBoundVector( std::vector<int>::iterator first, std::vector<int>::iterator last, int value);
		std::list<int>::iterator lowerBoundList( std::list<int>::iterator first, std::list<int>::iterator last, int value);

		size_t _vectComparisons;
		size_t _listComparisons;
		
		void writeLog(const std::vector<int>& input);
		void printVector(std::ofstream& log, const std::vector<int>& vect);
		void printList(std::ofstream& log, const std::list<int>& li);
		size_t fordJohnsonComparisons(size_t n);
		bool isSortedVector(const std::vector<int>& vect);
		bool sameSizeVector( const std::vector<int>& input, const std::vector<int>& output);
		bool isSortedList(const std::list<int>& li);
		bool sameSizeList( const std::vector<int>& input, const std::list<int>& output);

} ;

