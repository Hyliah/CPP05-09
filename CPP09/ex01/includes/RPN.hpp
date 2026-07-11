/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlichten <hlichten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:28:58 by hlichten          #+#    #+#             */
/*   Updated: 2026/07/11 13:22:25 by hlichten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <deque>
#include <iostream>

class RPN{
	private :
		//std::stack<int> _values;
		std::deque<int> _values;
		
	public :
		RPN();
		RPN(const RPN &other);
		RPN& operator= (const RPN &other);
		~RPN();
		
		void calValues(const std::string& val);
};