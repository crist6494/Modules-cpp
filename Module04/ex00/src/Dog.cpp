/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 18:27:28 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->_type = "Dog";
	std::cout<<"Default constructor called from Dog: NO NAME"<<std::endl;
}

Dog::Dog(const std::string& name)
	:Animal(name)
{
	this->_type = "Dog";
	this->_name = name;
	std::cout<<"Constructor with parameters called from Dog: "<< this->_name <<std::endl;
}

Dog::~Dog()
{
	std::cout<<"Destructor called from Dog " <<std::endl;
}

Dog::Dog(const Dog& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called from Dog"<<std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout<<"Assignation operator called from Dog"<<std::endl;
	Animal::operator=(src);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Guuau guuau !!!" << std::endl;
}

