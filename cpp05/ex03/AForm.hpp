/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:11:36 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 14:53:22 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>
#include "Bureaucrat.hpp"

#define LOW 150
#define HIGH 1

class Bureaucrat;

class AForm
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
		
		AForm();
		AForm(const std::string name, const int signGrade, const int executeGrade);
		virtual ~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& __unused other);

		const std::string getName() const;
		bool isFormSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat& worker);
		bool isExecutable(const Bureaucrat& executor) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};


std::ostream& operator<<(std::ostream& stream, const AForm& form);

#endif
