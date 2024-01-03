/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:31:10 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/20 13:21:27 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		bool isOperation(std::string operation);
		bool isValidDigit(std::string operand);
		double convert(std::string expression);
	private:
		std::string expression;
		std::stack<double> mstack;
};

#endif
