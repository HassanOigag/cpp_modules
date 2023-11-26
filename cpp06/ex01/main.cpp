/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:43:24 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/26 13:53:00 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{	
	Data data = {24, 180, 60};
	std::cout << "data address : " << &data << std::endl;
	
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "value of serializer : " << raw << std::endl;
	
	Data *desData = Serializer::deserialize(raw);
	std::cout << "value of deserializer : " << desData << std::endl;

	std::cout << "age    : " << desData->age << std::endl;
	std::cout << "height : " << desData->height << std::endl;
	std::cout << "weight : " << desData->weight << std::endl;
	return (0);
}
