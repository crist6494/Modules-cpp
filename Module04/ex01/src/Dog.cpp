/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 19:11:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->_type = "Dog";
	std::cout<<"Default constructor called from Dog"<<std::endl;
	this->_dogBrain = new Brain();
}

Dog::~Dog()
{
	std::cout<<"Destructor called from Dog " <<std::endl;
	delete this->_dogBrain;
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

