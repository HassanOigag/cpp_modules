/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:59:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/01 21:34:52 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <ostream>
class Fixed
{
	public:
		Fixed();
		// Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int	value;
		static const int nfBits;//number of fractional bits
		
};
std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif
