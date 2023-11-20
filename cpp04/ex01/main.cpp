/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:04:23 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/16 17:36:14 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const int n = 10;
	const int half = n / 2;
	Animal** animals = new Animal*[n];
	if (!animals)
		return 0;
	for (int i = 0; i < half; i++)
		animals[i] = new Cat();
	for (int i = half; i < n; i++)
		animals[i] = new Dog();

	std::cout << "-------------------------------------" << std::endl;
	for (int i = 0; i < n; i++)
		animals[i]->makeSound();
	std::cout << "-------------------------------------" << std::endl;
	for (int j = 0; j < n; j++)
		delete animals[j];
	delete[] animals;
	return (0);
}
