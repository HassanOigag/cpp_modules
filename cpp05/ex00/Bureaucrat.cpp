/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:25:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/18 17:42:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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