/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/18 20:02:16 by cmorales         ###   ########.fr       */
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
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& src);
		~Fixed();
		Fixed &operator=(const Fixed &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const; 
	private:
		int						_value;
		static const int _nbBits = 8;
};

std::ostream &operator<<(std::ostream &ost, const Fixed &obj);

#endif