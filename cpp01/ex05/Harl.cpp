/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <student.1337.ma>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:32:19 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/29 18:38:38 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "DEBUG\n"
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
    << "I really do!\n";
}

void Harl::info(void)
{
    std::cout << "INFO\n"
    << "I cannot believe adding extra bacon costs more money. You didn't put "
    << "enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
    std::cout << "WARNING\n"
    << "I think I deserve to have some extra bacon for free. I've been coming for"
    << " years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
    std::cout << "ERROR\n"
    << "This is unacceptable! I want to speak to the manager now.\n";
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
    harlFunc functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = index(level);
    if (i != -1)
    {
        harlFunc func = functions[i];
        (this->*func)();
    }
}