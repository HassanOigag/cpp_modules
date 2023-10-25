/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/25 17:30:05 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void clear_buffer()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int	isStrAllDigits(std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}


int getUserInput(std::string prompt, std::string& str)
{
	while (true)
	{
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, str))
			return 0;
		if (str.empty())
			std::cout << "this field cannot be empty" << std::endl;
		else if (prompt == "phone number" && !isStrAllDigits(str))
			std::cout << "phone number should be a number" << std::endl;
		else
			break;
	}
	return 1;
}

void addContact(PhoneBook& pb, int id)
{
	Contact newContact;
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;
	if (!getUserInput("first name", first_name)
		|| !getUserInput("last name", last_name)
		|| !getUserInput("nickname", nick_name)
		|| !getUserInput("phone number", phone_number)
		|| !getUserInput("darkest secret", darkest_secret))
		return;
	newContact = Contact(id, first_name, last_name, nick_name, phone_number, darkest_secret);
	pb.addContact(newContact);
}

void searchContacts(PhoneBook& pb)
{
	int index;
	Contact contact;
	if (pb.getCurrentSize() == 0)
	{
		std::cout << "phonebook is empty." << std::endl;
		return;
	}
	pb.printContacts();
	while (true)
	{
		std::cout << "enter the index of the contact: ";
		std::cin >> index;
		if (std::cin.eof())
			return;
		if (std::cin.fail())
		{
			std::cout << "invalid index" << std::endl;
			clear_buffer();
		}
		else if (index < 0 || index >= pb.getCurrentSize())
			std::cout << "index out of range" << std::endl;
		else
			break;
	}
	contact = pb.getContact(index);
	contact.print();
	clear_buffer();
}

int main() {
	int id = 0;
	std::string command;
	PhoneBook pb = PhoneBook();
	while (true)
	{
		std::cout << "commands: ADD, SEARCH, EXIT" << "$ ";
		if (!std::getline(std::cin, command) || command == "EXIT")
			break;
		else if (command == "ADD")
		{
			addContact(pb, id);
			id++;
		}
		else if (command == "SEARCH")
			searchContacts(pb);
	}
	return (0);
}
