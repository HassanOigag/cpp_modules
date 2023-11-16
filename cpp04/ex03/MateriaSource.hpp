/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:37:29 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 16:55:28 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

#define SIZE 4

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		void printMaterias() const;
		void deleteMaterias();
	private:
		AMateria **materias;
		unsigned int index;
	
};

#endif
