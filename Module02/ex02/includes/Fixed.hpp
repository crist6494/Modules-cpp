/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:43 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/28 18:08:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& src);
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		
		Fixed& operator=(const Fixed& obj);
		
		bool operator>(const Fixed& obj) const;
		bool operator<(const Fixed& obj) const;
		bool operator>=(const Fixed& obj) const;
		bool operator<=(const Fixed& obj) const;
		bool operator==(const Fixed& obj) const;
		bool operator!=(const Fixed& obj) const;

		Fixed operator+(const Fixed& obj) const;
		Fixed operator-(const Fixed& obj) const;
		Fixed operator/(const Fixed& obj) const;
		Fixed operator*(const Fixed& obj) const;
		
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int n);
		Fixed operator--(int n);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
	private:
		int						_value;
		static const int _nbBits = 8;
};

std::ostream& operator<<(std::ostream& ost, const Fixed& obj);

#endif