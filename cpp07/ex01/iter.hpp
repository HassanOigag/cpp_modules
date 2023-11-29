/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:12:21 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/28 15:30:02 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
template <typename T, typename FUNC>
void iter(T* array, unsigned int length, FUNC func)
{
    unsigned int i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

template <typename T>
void print(T arg)
{
    std::cout << "[" << arg << "]";
}
#endif