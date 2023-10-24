/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:51 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/24 16:28:35 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
    this->id = 0;
    this->firstName = "";
    this->lastName = "";
    this->nickName = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
}
Contact::Contact(int id, std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
    this->id = id;
    this->firstName = first_name;
    this->lastName = last_name;
    this->nickName = nick_name;
    this->phoneNumber = phone_number;
    this->darkestSecret = darkest_secret;
}

void Contact::print(void)
{
    std::cout << "ID             : " << this->id <<std::endl
              << "First Name     : " << this->firstName << std::endl
              << "Last Name      : " << this->lastName << std::endl
              << "Nick Name      : " << this->nickName << std::endl
              << "Phone Number   : " << this->phoneNumber << std::endl
              << "Darkest Secret : " << this->darkestSecret << std::endl;
}

int Contact::getId()
{
    return this->id;
}

std::string Contact::getFristName()
{
    return this->firstName;
}


std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickName()
{
    return this->nickName;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}

void Contact::setId(int id)
{
    this->id = id;
}

void Contact::setFristName(std::string first_name)
{
    this->firstName = first_name;
}

void Contact::setLastName(std::string last_name)
{
    this->firstName = last_name;
}

void Contact::setNickName(std::string nick_name)
{
    this->nickName = nick_name;
}

void Contact::setPhoneNumber(std::string phone_number)
{
    this->phoneNumber = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret)
{
    this->darkestSecret = darkest_secret;
}