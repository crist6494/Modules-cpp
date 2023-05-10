/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 17:12:23 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-------------------------------ex00------------------------------------*/

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called" <<std::endl;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
	std::cout<<"Assignation operator called "<<std::endl;
	this->_value = obj.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}


int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
