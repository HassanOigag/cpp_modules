/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:25:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 15:15:23 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("")
{
    this->grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < HIGH)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > LOW)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name)
{
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->grade = other.grade;
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increment()
{
    int newGrade = this->grade - 1;
    if (newGrade < HIGH)
        throw Bureaucrat::GradeTooHighException();
    this->grade = newGrade;
}

void Bureaucrat::decrement()
{
    int newGrade = this->grade + 1;
    if (newGrade > LOW)
        throw Bureaucrat::GradeTooLowException();
    this->grade = newGrade;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj)
{
    stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
    return stream;
}


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

void Bureaucrat::signForm(const AForm& form) const
{
    if (form.isFormSigned())
        std::cout << this->name << " signed " << form.getName() << std::endl;
    else
        std::cout << this->name << " couldn't sign " << form.getName() << " becuase the grade is too low" << std::endl;    
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "could not execute " << this->getName() << " because the grade is too low" << std::endl;
    }
}