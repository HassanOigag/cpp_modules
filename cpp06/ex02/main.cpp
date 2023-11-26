/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:11:41 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/26 16:45:47 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "helpers.hpp"

int main()
{
	Base *p = generate();
	
	A a;
	B b;
	C c;
	
	Base &ra = a;
	Base &rb = b;
	Base &rc = c;
	
	identify(p);
	
	identify(ra);
	identify(rb);
	identify(rc);
	delete p;
	return 0;
}
