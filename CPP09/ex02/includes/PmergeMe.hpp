/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:15 by hlichten          #+#    #+#             */
/*   Updated: 2026/06/21 16:52:02 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
#include <utility>

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
        std::vector<int>& getVector();
        std::list<int>& getList();

        std::vector<size_t> jacobsthalIndexes(size_t n);

        void sortList(std::list<int> li);

        std::vector<int> sortVector(std::vector<int> vect);
} ;