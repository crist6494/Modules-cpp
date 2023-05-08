/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/08 19:20:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout<<"Default constructor called from Animal: NO NAME"<<std::endl;
}

Animal::~Animal()
{
	std::cout<<"Destructor called from Animal " <<std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout<<"Copy constructor called from Animal"<<std::endl;
	*this = src;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout<<"Assignation operator called from Animal"<<std::endl;
	this->_type = src._type;
	return *this;
}
