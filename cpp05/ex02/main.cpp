/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:29:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/19 15:56:43 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
	try
	{
		AForm *form = new ShrubberyCreationForm("house");
		std::cout << *form;
		Bureaucrat hassan("hassan", 150);
		std::cout << hassan;
		form->beSigned(hassan);
		std::cout << *form;
		form->execute(hassan);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

// void draw_ascii_tree()
// {
// 	std::cout <<
//     	 <<"                                             .\n"
//            "                                  .         ;  "
//            "      .              .              ;%    ;;   "
//                    ,           ,                :;%  %;   
//                     :         ;                   :;%;'     .,   
//            ,.        %;     %;            ;        %;'    ,;
//              ;       ;%;  %%;        ,     %;    ;%;    ,%'
//               %;       %;%;      ,  ;       %;  ;%;   ,%;' 
//                ;%;      %;        ;%;        % ;%;  ,%;'
//                 `%;.     ;%;     %;'         `;%%;.%;'
//                  `:;%.    ;%%. %@;        %; ;@%;%'
//                     `:%;.  :;bd%;          %;@%;'
//                       `@%:.  :;%.         ;@@%;'   
//                         `@%.  `;@%.      ;@@%;         
//                           `@%%. `@%%    ;@@%;        
//                             ;@%. :@%%  %@@%;       
//                               %@bd%%%bd%%:;     
//                                 #@%%%%%:;;
//                                 %@@%%%::;
//                                 %@@@%(o);  . '         
//                                 %@@@o%;:(.,'         
//                             `.. %@@@o%::;         
//                                `)@@@o%::;         
//                                 %@@(o)::;        
//                                .%@@@@%::;         
//                                ;%@@@@%::;.          
//                               ;%@@@@%%:;;;. 
//                           ...;%@@@@@%%:;;;;,.. 
	
// }