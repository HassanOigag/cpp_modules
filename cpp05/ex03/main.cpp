/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 17:03:16 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form = NULL;
	try
	{
		Intern amine;
		Bureaucrat hassan("hassan", 1);
		form = amine.makeForm("robotomy request", "bender");
		if (!form)
			return 1;
		std::cout << *form;
		std::cout << hassan;
		form->beSigned(hassan);
		hassan.signForm(*form);
		std::cout << *form;
		hassan.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	if (form)
		delete form;
	return (0);
}


