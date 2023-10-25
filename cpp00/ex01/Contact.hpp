/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:11:49 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/25 17:29:56 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	public:
		Contact();
		Contact(int id, std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
		
		int getId();
		std::string getFristName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
		
		void setId(int id);
		void setFristName(std::string first_name);
		void setLastName(std::string last_name);
		void setNickName(std::string nick_name);
		void setPhoneNumber(std::string phone_number);
		void setDarkestSecret(std::string darkest_secret);

		void print(void);
		
	private:
		int			id;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
