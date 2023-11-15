/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:36:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/15 10:46:34 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);

		AMateria* clone() const;	
		void use(ICharacter& target);
};

#endif
