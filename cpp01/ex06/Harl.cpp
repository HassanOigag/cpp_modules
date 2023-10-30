/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:53:08 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 13:16:15 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n"
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
    << "I really do!\n\n";
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n"
    << "I cannot believe adding extra bacon costs more money. You didn't put "
    << "enough bacon in my burger! If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n"
    << "I think I deserve to have some extra bacon for free. I've been coming for"
    << " years whereas you started working here since last month.\n\n";
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\n"
    << "This is unacceptable! I want to speak to the manager now.\n\n";
}

int index(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return (i);
    }
    return (-1);
}

void Harl::complain(std::string level)
{
  
    int i = index(level);
    switch (i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}
