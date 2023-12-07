/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:03:04 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/07 17:35:47 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stack>
#include <iostream>
#include "MutantStack.hpp"
#include <list>
int main()
{
	std::cout << "their tests" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	//my tests
	std::cout << "my tests using list" << std::endl;
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(10);
	mlist.push_back(15);
	mlist.push_back(20);
	std::cout << "size : " << mlist.size() << std::endl;
	std::list<int>::iterator lstIt = mlist.begin();
	std::list<int>::iterator lstIte = mlist.end();
	while (lstIt != lstIte)
	{
		std::cout << *lstIt << std::endl;
		lstIt++;
	}
	return (0);
}
