/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:13:50 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 12:23:10 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iomanip>

AForm::AForm() : name(""), signGrade(1), executeGrade(1)
{
    this->isSigned = false;
}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade)
{
    if (this->signGrade < HIGH || this->executeGrade < HIGH)
        throw AForm::GradeTooHighException();
    if (this->signGrade > LOW || this->executeGrade > LOW)
        throw AForm::GradeTooLowException();
    this->isSigned = false;
}

AForm::~AForm()
{

}

AForm::AForm(const AForm& other) : name(other.name), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
    this->isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& __unused other)
{
    return *this;
}

const std::string AForm::getName() const
{
    return this->name;
}

bool AForm::isFormSigned() const
{
    return this->isSigned;    
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void AForm::beSigned(const Bureaucrat& worker)
{
    if (worker.getGrade() > this->signGrade)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
    int columnSize = 25;
    int columns = 4;
    std::string isFormSigned = form.isFormSigned() ? "signed" : "not signed";
    std::string border = " ";
    for (int i = 0; i < (columns * columnSize) + 11; i++)
        border += "-";
    stream <<  border << std::endl;
    stream << "| " << std::left << std::setw(columnSize) << "Form Name" << " | "
           << std::setw(columnSize) << "Sign Grade" << " | "
           << std::setw(columnSize) << "Execute Grade" << " | "
           << std::setw(columnSize) << "Status" << " | " << std::endl;
    stream << border << std::endl;
    stream << "| " << std::setw(columnSize) << form.getName() << " | "
           << std::setw(columnSize) << form.getSignGrade() << " | "
           << std::setw(columnSize) << form.getExecuteGrade() << " | "
           << std::setw(columnSize) << isFormSigned << " | " << std::endl;
    stream << border << std::endl;
    return stream;
}


bool AForm::isExecutable(const Bureaucrat& executor) const
{
    return this->isSigned && (executor.getGrade() <= this->executeGrade); 
}