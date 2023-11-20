/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/20 19:15:00 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
int main()
{
	AForm *form;
	try
	{
		form = new PresidentialPardonForm("1337");
		std::cout << *form;
		Bureaucrat hassan("hassan", 5);
		std::cout << hassan;
		form->beSigned(hassan);
		std::cout << *form;
		hassan.executeForm(*form);
		system("leaks -q bureaucrat");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete form;
	return (0);
}


