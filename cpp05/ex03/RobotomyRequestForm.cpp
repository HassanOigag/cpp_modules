/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:04:46 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/20 18:35:47 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (!this->isExecutable(executor))
        throw AForm::GradeTooLowException();
    srand(time(NULL));
    std::cout << "drilling noises..." <<  std::endl;
    int random = (rand() % 10) + 1;
    if (random >= 5)
        std::cout << this->target << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}
