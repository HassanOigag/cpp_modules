/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:18:46 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/16 16:48:30 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include <sstream>



int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open the file." << std::endl;
        return 1;
    }
    try
    {
        std::string inputFileName = argv[1];
        BitcoinExchange be;
        // be.printData();
        be.exchange(inputFileName);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}