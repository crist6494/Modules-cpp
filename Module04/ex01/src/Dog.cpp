/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/24 17:36:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->_type = "Dog";
	std::cout<<"Default constructor called from Dog"<<std::endl;
	this->_dogBrain = new Braxin();
}
x
Dog::~Dog()
{
	std::cout<<"Destructor called from Dog " <<std::endl;
	delete this->_dogBrain;
}

Dog::Dog(const Dog& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called from Dog" <<std::endl;
	this->_dogBrain = new Brain();
	*(this->_dogBrain) = *(src._dogBrain);
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout<<"Assignation operator called from Dog" <<std::endl;
	if(this != &src)
	{
		Animal::operator=(src);
		*(this->_dogBrain) = *(src._dogBrain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Guuau guuau !!!" << std::endl;
}
