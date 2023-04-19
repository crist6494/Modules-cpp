/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:47:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/19 20:47:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*-------------------------------ex00------------------------------------*/

Fixed::Fixed()
{
	//std::cout<<"Default constructor called"<<std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	//std::cout<<"Destructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Fixed&	Fixed::operator=(const Fixed &obj)
{
	//std::cout<<"Assignation operator called "<<std::endl;
	this->_value = obj._value;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*-------------------------------ex01------------------------------------*/

Fixed::Fixed(const int n)
{
	//std::cout<<"Int constructor called"<<std::endl;
	this->_value = n << _nbBits;
}

Fixed::Fixed(const float n)
{
	//std::cout<<"Float constructor called"<<std::endl;
	this->_value = (int)roundf(n * (1 << _nbBits));
}

int		Fixed::toInt() const
{
	return (this->_value >> _nbBits);
}

float	Fixed::toFloat() const
{
	return ((float)this->_value) / (1 << _nbBits);
}

std::ostream &operator<<(std::ostream &ost, const Fixed &obj)
{
	ost << obj.toFloat();
	return ost;
}

/*-------------------------------ex02------------------------------------*/

/*---------Comparison operators-----------*/

bool Fixed::operator>(const Fixed &obj) const
{
	return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->getRawBits() != obj.getRawBits());
}

/*---------Arithmetic operators-----------*/

Fixed Fixed::operator+(const Fixed &obj) const
{
	return ((Fixed)(this->getRawBits() + obj.getRawBits()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return ((Fixed)(this->getRawBits() - obj.getRawBits()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return ((Fixed)(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return ((Fixed)(this->toFloat() / obj.toFloat()));
}

/*---------Increment and Decrement operators-----------*/

Fixed & Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed & Fixed::operator--()
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator++(int n)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--(int n)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/*----------------------Max and min-----------------------*/

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if(a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if(a < b)
		return b;
	return a;	
}

Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if(a > b)
		return ((Fixed&)b);
	return ((Fixed&)a);
}

Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if(a < b)
		return ((Fixed&)b);
	return ((Fixed&)a);

}

