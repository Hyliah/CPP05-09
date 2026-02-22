/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:17:51 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/22 23:55:42 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>{
    public :
    MutantStack(){};
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    MutantStack& operator= (const MutantStack &other){
        std::stack<T>::operator=(other); return *this;}
    ~MutantStack(){};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
} ;