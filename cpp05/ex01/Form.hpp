/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:36 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 12:07:20 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

#define LOW 150
#define HIGH 1

class Bureaucrat;

class Form
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
		
		Form();
		Form(const std::string name, const int signGrade, const int executeGrade);
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& __unused other);

		const std::string getName() const;
		bool isFormSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat& worker);
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};


std::ostream& operator<<(std::ostream& stream, const Form& form);

#endif
