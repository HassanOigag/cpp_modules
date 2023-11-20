/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 12:20:03 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form form("extrait", 5, 20);
		std::cout << form;
		Bureaucrat hassan("hassan", 5);
		std::cout << hassan;
		form.beSigned(hassan);
		hassan.signForm(form);
		std::cout << form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
