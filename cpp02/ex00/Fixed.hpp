/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:59:12 by hoigag            #+#    #+#             */
/*   Updated: 2023/11/01 18:21:19 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int		getRawBits(void);
		void	setRawBits(int const raw);
	private:
		int	value;
		static const int nfBits;//number of fractional bits
};

#endif
