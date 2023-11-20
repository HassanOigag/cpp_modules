/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:54:25 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/20 18:20:05 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
    this->target = other.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	AForm::operator=(other);
    return *this;
}

void draw_tree(std::ofstream& file)
{
	file      << "                      ___\n"
			  << "                _,-'\"\"   \"\"\"\"`--.\n"
			  << "             ,-'          __,,-- \\\n"
			  << "           ,'    __,--\"\"\"\"dF      )\n"
			  << "          /   .-\"Hb_,--\"\"dF      /\n"
			  << "        ,'       _Hb ___dF\"-._,-'\n"
			  << "      ,'      _,-\"\"\"\"   \"\"--..__\n"
			  << "     (     ,-'                  `.\n"
			  << "      `._,'     _   _             ;\n"
			  << "       ,'     ,' `-'Hb-.___..._,-'\n"
			  << "       \\    ,'\"Hb.-'HH`-.dHF\"\n"
			  << "        `--'   \"Hb  HH  dF\"\n"
			  << "                \"Hb HH dF\n"
			  << "                 \"HbHHdF\n"
			  << "                  |HHHF\n"
			  << "                  |HHH|\n"
			  << "                  |HHH|\n"
			  << "                  |HHH|\n"
			  << "                  |HHH|\n"
			  << "                  dHHHb\n"
			  << "                .dFd|bHb.               o\n"
			  << "      o       .dHFdH|HbTHb.          o /\n"
			  << "\\  Y  |  \\__,dHASSAN|HASSANb.__Krogg  Y\n"
			  << "##########################################\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isExecutable(executor))
        throw AForm::GradeTooLowException();
    std::string fileName = this->target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());
    if (!outFile)
        throw std::runtime_error("could not open file");
    draw_tree(outFile);
    outFile.close();
}