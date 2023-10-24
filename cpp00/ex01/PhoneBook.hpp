/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:10:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/24 17:57:16 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define PHONE_BOOK_SIZE 8
#define COLUMN_WIDH 10

class PhoneBook {
	public:
		PhoneBook();
		
		int getCurrentSize();
		Contact	getContact(int index);
		void addContact(Contact c);
		void printContacts();
		std::string format(std::string str);
	private:
		Contact contacts[PHONE_BOOK_SIZE];
		int		current_size;
};

#endif
