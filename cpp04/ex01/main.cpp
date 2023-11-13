/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:04:23 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/13 14:43:19 by hoigag           ###   ########.fr       */
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
	int n = 10;
	Animal** animals = new Animal*[n];
	if (!animals)
		return 0;
	for (int i = 0; i < n / 2; i++)
		animals[i] = new Cat();
	for (int i = n / 2; i < n; i++)
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
