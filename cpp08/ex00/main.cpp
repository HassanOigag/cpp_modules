/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:33:36 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/04 17:49:35 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <set>


int main()
{
    try
    {
        std::list<int> lst;
        std::vector<int> vector;
        std::set<int> myset;
        for (int i = 0; i < 10; i++)
        {
            lst.push_back(i);
            vector.push_back(i);
            myset.insert(i);
        }
        std::cout << easyfind(lst, 9) << std::endl;
        std::cout << easyfind(vector, 9) << std::endl;
        std::cout << easyfind(myset, 9) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}