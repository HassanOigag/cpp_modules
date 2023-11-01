/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:54:57 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/27 12:06:50 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "string address   : " << &str << std::endl;
    std::cout << "stringPTR value  : " << stringPTR << std::endl;
    std::cout << "stringREF address: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "string value       :" << str <<  std::endl;
    std::cout << "stringPTR points to:" << *stringPTR <<  std::endl;
    std::cout << "stringREF value    :" << stringREF <<  std::endl;
    return 0;
}