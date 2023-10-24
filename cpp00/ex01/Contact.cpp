/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:51 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/23 13:41:52 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
Contact::Contact() {
    this->first_name = "";
    this->last_name = "";
    this->nick_name = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick_name = nick_name;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

void Contact::print(void)
{
    std::cout << "First Name     : " << this->first_name << std::endl
              << "Last Name      : " << this->last_name << std::endl
              << "Nick Name      : " << this->nick_name << std::endl
              << "Phone Number   : " << this->phone_number << std::endl
              << "Darkest Secret : " << this->darkest_secret << std::endl;
}
