/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:54:25 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 15:52:20 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
    this->target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    this->target = other.target;
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& __unused other)
{
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isExecutable(executor))
        throw AForm::GradeTooLowException();
    std::string fileName = this->target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());
    if (!outFile)
        throw std::runtime_error("could not open file");
    outFile << "tree";
    outFile.close();
}