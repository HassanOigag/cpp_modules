/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:28:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/13 17:13:32 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
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

int parseDate(std::string date)
{
    std::stringstream stream;
    stream.str(date);
    int year, month, day;
    
}


void loadInputFile(std::string fileName)
{
    std::fstream inputFile(fileName.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("could not open the input file");
    std::string line;
    getline(inputFile, line);
    while (getline(inputFile, line))
    {
        std::stringstream stream;
        stream.str(line);
        std::string date;
        std::string price;
        getline(stream, date, '|');
        getline(stream, price);
        if (price.empty())
            std::cout << "invlid input" << std::endl;
        else
            std::cout << "<" << date << ">" << " " << "<" << price << ">" << std::endl;
    }
}