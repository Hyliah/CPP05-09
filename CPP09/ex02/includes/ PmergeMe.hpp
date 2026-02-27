/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    PmergeMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:33:15 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/27 18:29:29 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <iostream>

class PmergeMe{
    private :
        std::list<int> _li;
        std::vector<int> _vect;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe& operator=(const PmergeMe &other);
        ~PmergeMe();
} ;