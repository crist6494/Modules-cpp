/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:35:59 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->_type = "Animal";
	std::cout<<"Default constructor called from AAnimal"<<std::endl;
}

AAnimal::~AAnimal()
{
	std::cout<<"Destructor called from AAnimal " <<std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout<<"Copy constructor called from AAnimal"<<std::endl;
	*this = src;
}

AAnimal& AAnimal::operator=(const AAnimal& src)
{
	std::cout<<"Assignation operator called from AAnimal"<<std::endl;
	this->_type = src._type;
	return *this;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

