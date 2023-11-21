/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:45 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/21 17:02:51 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& __unused other);
		Intern& operator=(const Intern& __unused other);
		AForm *makeForm(std::string formName, std::string target);
};

typedef  AForm* (*createForm)(std::string);

#endif
