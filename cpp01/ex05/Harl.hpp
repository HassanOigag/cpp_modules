/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:30:05 by hoigag            #+#    #+#             */
/*   Updated: 2023/10/30 15:19:04 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
//addf
class Harl
{
	public:
		void complain(std::string level);
	private: 
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};
typedef void(Harl::*harlFunc)();
#endif
