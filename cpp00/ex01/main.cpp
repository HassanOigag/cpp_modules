/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:30:43 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/23 13:41:07 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main() {
	Contact	c = Contact("hassan", "oigag", "hoigag", "123456790", "adsfadsfasfadsfadsf");
	c.print();
	return (0);
}
