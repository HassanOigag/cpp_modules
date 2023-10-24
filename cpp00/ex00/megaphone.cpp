/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:28:47 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/22 13:37:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void print_upper(std::string str)
{
    for (char c: str)
    {
        char upper = toupper(c);
        std::cout << upper;
    }
}


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1;i < argc; i++)
        print_upper(argv[i]);
    std::cout << std::endl;
    return (0);
}