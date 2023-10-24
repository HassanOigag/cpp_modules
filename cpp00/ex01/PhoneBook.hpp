/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:10:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/23 13:44:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define PHONE_BOOK_SIZE 8

class PhoneBook {
	public:
		PhoneBook();
	private:
		Contact contacts[PHONE_BOOK_SIZE];
		int		index;
};

#endif
