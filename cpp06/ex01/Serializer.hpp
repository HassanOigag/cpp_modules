/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:33:42 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/26 13:53:25 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <cstdint>

struct Data
{
	int age;
	int height;
	int weight;
};

class Serializer
{
	public:
		~Serializer();
		Serializer(const Serializer& __unused other);
		Serializer& operator=(const Serializer& other);
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
};

#endif
