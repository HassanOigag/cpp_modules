/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:18:48 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/29 17:41:07 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>



int main()
{
    unsigned int length = 4;
    int numbers[] = {1, 2, 3, 4};
    std::string names[] = {"hassan", "houssine", "jamal", "amine"};

    iter(numbers, length, print<int>);
    std::cout << std::endl;
    iter(names, length, print<std::string>);
    return 0;
}