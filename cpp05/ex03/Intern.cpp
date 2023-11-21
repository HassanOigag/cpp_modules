/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:05:14 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 17:02:03 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{

}

Intern::Intern(const Intern& __unused other)
{

}

Intern& Intern::operator=(const Intern& __unused other)
{
    return *this;
}

int getIndex(std::string formName)
{
    std::string forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for (int i = 0; i < 3; i++)
    {
        if (forms[i] == formName)
            return i;
    }
    return -1;
}

AForm *createPresidentialPardonForm(std::string target)
{
    std::cout << "Intern creates a PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *createRobotomyRequestForm(std::string target)
{
    std::cout << "Intern creates a RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm *createShrubberyCreationForm(std::string target)
{
    std::cout << "Intern creates a ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    int index = getIndex(formName);
    AForm* form;
    if (index == -1)
    {
        std::cout << "Could not find form" << std::endl;
        form = NULL;
    }
    else
    {
        createForm forms[3] = {&createPresidentialPardonForm, &createRobotomyRequestForm, &createShrubberyCreationForm};
        form = forms[index](target);
    }
    return form;
}