/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:59:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/04 15:34:57 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>
class Fixed
{
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed(const Fixed& other);
		
		Fixed&  operator=(const Fixed& other);
		Fixed 	operator+(const Fixed& other) const;
		Fixed 	operator-(const Fixed& other) const;
		Fixed 	operator*(const Fixed& other) const;
		Fixed 	operator/(const Fixed& other) const;

		bool	operator==(const Fixed& fixed1) const;
		bool	operator!=(const Fixed& fixed1) const;
		bool	operator>(const Fixed& fixed1) const;
		bool	operator<(const Fixed& fixed1) const;
		bool	operator>=(const Fixed& fixed1) const;
		bool	operator<=(const Fixed& fixed1) const;

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static	Fixed&	min(Fixed& fixed1, Fixed& fixed2);
		static	const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static	Fixed&	max(Fixed& fixed1, Fixed& fixed2);
		static	const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);

		int		getRawBits(void) const;	
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int	value;
		static const int nfBits;//number of fractional bits	
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);
int power(int base, int power);
	
#endif
