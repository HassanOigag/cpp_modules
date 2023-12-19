/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:27:31 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/18 11:22:23 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <string>
#include <map>
class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void printData() const;
		void exchange(std::string fileName);
	private:
		std::string db_filename;
		std::map<int, double> dataBase;
		void loadDataBase();
		void parseDate(std::string& date);
		double getDouble(std::string& literal);
		int dateToInt(std::string &date);
		double getValue(int key);
		// std::string intToDate(int date);
		std::pair<int, double> parseLine(std::string line, char sep);
};
void loadInputFile(std::string fileName);

#endif
