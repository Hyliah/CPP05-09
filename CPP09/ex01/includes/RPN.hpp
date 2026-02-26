/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:28:58 by hlichten          #+#    #+#             */
/*   Updated: 2026/02/26 16:01:30 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

class RPN{
	private :
		std::stack<int> _values;
		
	public :
		RPN();
		RPN(const RPN &other);
		RPN& operator= (const RPN &other);
		~RPN();
		
		void calValues(const std::string& val);
};

// s.push(10);
// s.pop();
// int x = s.top();
// s.size();
// s.empty();