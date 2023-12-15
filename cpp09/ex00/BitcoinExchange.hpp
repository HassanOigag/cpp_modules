/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:27:31 by hoigag            #+#    #+#             */
/*   Updated: 2023/12/15 15:27:52 by hoigag           ###   ########.fr       */
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
		std::map<std::string, double> dataBase;
		void loadDataBase();
};
void loadInputFile(std::string fileName);

#endif
