/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:21:21 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:06:22 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria& other);
		std::string const & getType() const;
		AMateria& operator=(const AMateria& __unused other);
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string type;
};

#endif
