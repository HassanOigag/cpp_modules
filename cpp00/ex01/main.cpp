/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/24 19:43:40 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int getUserInput(std::string prompt, std::string& str)
{
	while (true)
	{
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, str))
			return -1;
		if (str.empty())
			std::cout << "this field cannot be empty" << std::endl;
		else
			break;
	}
	return 1;
}

int addContact(PhoneBook& pb)
{
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;
	if (!getUserInput("first name", first_name))
	{
		std::cout << "end of line encountered" << std::endl;
		return 0;
	}
	return 1;
}

void searchContacts(PhoneBook& pb)
{
	std::cout << "searching contacts" << std::endl;
}

int main() {
	int i = 0;
	std::string command;
	PhoneBook pb = PhoneBook();
	while (true)
	{
		std::cout << "commands: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "$ ";
		if (!std::getline(std::cin, command) || command == "EXIT")
			break;
		else if (command == "ADD")
		{
			if (!addContact(pb))
				continue;
		}
		else if (command == "SEARCH")
			searchContacts(pb);
	}
	return (0);
}
