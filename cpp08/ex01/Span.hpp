/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:53:38 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/05 13:26:39 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		void addNumber(int n);
		void printSpan() const;
		unsigned int longestSpan();
		unsigned int shortestSpan();
		void fillSpan();
	private:
		unsigned int N;
		unsigned int currentSize;
		std::vector<int> span;
};

#endif
