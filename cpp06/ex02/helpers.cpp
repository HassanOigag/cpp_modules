/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:59:01 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/26 16:46:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
    Base *res;
    srand(time(NULL));
    int number = rand() % 3;
    switch (number)
    {
        case 0:
            res = new A();
            break;
        case 1:
            res = new B();
            break;
        case 2:
            res = new C();
            break;
        default:
            res = NULL;
    }
    return res;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try
    {
        B& a = dynamic_cast<B&>(p);
        (void)a;
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception& e) {}

    try
    {
        C& a = dynamic_cast<C&>(p);
        (void)a;
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    
}