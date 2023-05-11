/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 11:43:21 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout<<"Default constructor called from WrongAnimal: NO NAME"<<std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"Destructor called from WrongAnimal " <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout<<"Copy constructor called from WrongAnimal"<<std::endl;
	*this = src;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout<<"Assignation operator called from WrongAnimal"<<std::endl;
	this->_type = src._type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal make a sound ....." << std::endl;
}
