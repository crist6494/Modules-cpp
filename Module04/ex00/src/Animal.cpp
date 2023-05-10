/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:59:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 18:26:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "";
	std::cout<<"Default constructor called from Animal: NO NAME"<<std::endl;
}

Animal::Animal(std::string name)
{
	this->_name = name;
	this->_type = "";
	std::cout<<"Constructor with parameters called from Animal: "<< this->_name <<std::endl;
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
	this->_name = src._name;
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << this->_name << " make a sound ....." << std::endl;
}

