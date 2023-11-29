/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:34:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/29 16:28:06 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <ostream>
#include <stdexcept>
#include <iostream>
template <typename T>
class Array
{
	public:
		Array()
		{
			this->length = 0;
			this->array = new T[0];
		}
		Array(unsigned int n)
		{
			this->length = n;
			this->array = new T[n]();
		}
		~Array()
		{
			if (this->array)
				delete[] this->array;
		}

		Array(const Array& other)
		{
			this->length = other.length;
			this->array = new T[other.length];
			for (unsigned int i = 0; i  < other.length; i++)
				this->array[i] = other.array[i];
		}

		Array& operator=(const Array& other)
		{
			if (this->length)
				delete[] this->array;
			this->array = new T[other.length];
			this->length = other.length;
			for (unsigned int i = 0; i < other.length; i++)
				this->array[i] = other.array[i];
			return *this;
		}
		
		unsigned int size() const 
		{
			return this->length;
		}
		
		T& operator[](unsigned int index) const
		{
			if (index < 0 || index >= this->size())
				throw std::runtime_error("index out of range");
			return this->array[index];
		}
	private:
		unsigned int length;
		T *array;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		stream << array[i] << " ";
	return stream;
}

#endif