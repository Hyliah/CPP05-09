/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:26:09 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/23 00:09:23 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
    std::cout << "=== MutantStack Test ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element   (should be 17):  " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop (should be 1):  " << mstack.size() << std::endl;

    // Adding more elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterating through the stack using the custom iterator
    std::cout << "Iterating MutantStack elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;


    std::cout << "\n=== std::list Test ===" << std::endl;
    std::list<int> alist;

    alist.push_back(5);
    alist.push_back(17);

    std::cout << "Back element       (should be 17):  " << alist.back() << std::endl;

    alist.pop_back();
    std::cout << "Size after pop_back (should be 1):  " << alist.size() << std::endl;

    // Adding more elements
    alist.push_back(3);
    alist.push_back(5);
    alist.push_back(737);
    alist.push_back(0);

    // Iterating through the list
    std::cout << "Iterating std::list elements:" << std::endl;
    for (std::list<int>::iterator it = alist.begin(); it != alist.end(); ++it)
        std::cout << *it << std::endl;

    // ----------------------------
    // Copying MutantStack to std::stack
    // ----------------------------
    std::stack<int> s(mstack);
    std::cout << "\nMutantStack copied to std::stack. Top element: " << s.top() << std::endl;

    return 0;
}
