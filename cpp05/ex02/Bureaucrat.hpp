/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:21:25 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 13:07:59 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>
#include "AForm.hpp"
#define LOW 150
#define HIGH 1

class AForm;

class Bureaucrat
{
	public:

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();
		void signForm(const AForm& form) const;
	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& obj);

#endif
