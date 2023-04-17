/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/17 20:37:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->value = 1;
	this->n = 4;
	this->name = "Default";
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called from" << this->name <<std::endl;
}

Fixed&	Fixed::operator=(const Fixed &obj)
{
	std::cout<<"Assignation operator called "<<std::endl;
	this->value = obj.getRawBits();
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
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

void	Fixed::print_class()
{
	std::cout<<std::endl;
	std::cout<<"Soy el constructor: "<< this->name<<std::endl;
	std::cout<<"Valor: "<< this->value<<std::endl;
	std::cout<<"Fract_bit: "<< this->fract_bit<<std::endl;
	std::cout<<"N: "<< this->n<<std::endl;
	std::cout<<std::endl;
}
