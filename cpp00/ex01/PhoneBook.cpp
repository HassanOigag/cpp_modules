/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:44:55 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/24 18:19:00 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
PhoneBook::PhoneBook()
{
    this->current_size = 0;
}

void PhoneBook::addContact(Contact c)
{
    this->contacts[c.getId() % PHONE_BOOK_SIZE] = c;
    if (this->current_size < PHONE_BOOK_SIZE)
        current_size++;
}

int PhoneBook::getCurrentSize()
{
    return this->current_size;
}

Contact PhoneBook::getContact(int index)
{
    return this->contacts[index];
}
std::string PhoneBook::format(std::string str)
{
    std::string newStr;
    if (str.length() > 10)
    {
        newStr = str.substr(0, COLUMN_WIDH - 1);
        newStr += ".";
    }
    else
        newStr = str;
    return newStr;
}
void PhoneBook::printContacts()
{
     std::cout << "*-------------------------------------------*" << std::endl
                << "|" << std::setw(COLUMN_WIDH) << "index" << "|" 
                << std::setw(COLUMN_WIDH) << "first name" << "|" 
                << std::setw(COLUMN_WIDH) << "last name" << "|" 
                << std::setw(COLUMN_WIDH) << "nick_name" << "|" 
                << std::endl
                << "*-------------------------------------------*" << std::endl;
    for (int i = 0; i < this->current_size; i++)
    {
        Contact c = this->getContact(i);
        std::cout << "|" << std::setw(COLUMN_WIDH) << c.getId() % PHONE_BOOK_SIZE << "|"
                  << std::setw(COLUMN_WIDH) << this->format(c.getFristName()) << "|"
                  << std::setw(COLUMN_WIDH) << this->format(c.getLastName()) << "|" 
                  << std::setw(COLUMN_WIDH) << this->format(c.getNickName()) << "|" 
                  << std::endl
                  << "*-------------------------------------------*" << std::endl;
        
    }
}


