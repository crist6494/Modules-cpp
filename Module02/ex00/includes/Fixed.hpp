/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/20 11:26:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed & operator=(const Fixed &obj);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int						_value;
		static const int _fract_bit = 8;
};


#endif