/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:28:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/11 18:13:08 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
BitcoinExchange::BitcoinExchange()
{
    this->db_filename = "data.csv";
}

BitcoinExchange::~BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    this->db_filename = other.db_filename;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    this->db_filename = other.db_filename;
    return *this;
}

void BitcoinExchange::loadData()
{
    std::ifstream file(this->db_filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open the file");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::stringstream stream;
        stream.str(line);
        std::string date;
        double exchangeRate;
        std::getline(stream, date, ',');
        stream >> exchangeRate;
        this->data.insert(std::make_pair(date, exchangeRate));
    }
}

void BitcoinExchange::printData() const
{
    std::map<std::string, double>::const_iterator it = this->data.cbegin();
    while (it  != data.cend())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}