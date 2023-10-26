/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/24 17:18:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	this->_type = "Cat";
	std::cout<<"Default constructor called from Cat"<<std::endl;
	this->_catBrain = new Brain();
}

Cat::~Cat()
{
	std::cout<<"Destructor called from Cat" <<std::endl;
	delete this->_catBrain;
}

Cat::Cat(const Cat& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called from Cat" <<std::endl;
	this->_catBrain = new Brain();
	*(this->_catBrain) = *(src._catBrain);
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout<<"Assignation operator called from Cat" <<std::endl;
	if(this != &src)
	{
		Animal::operator=(src);
		*(this->_catBrain) = *(src._catBrain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meauww Meauww !!!" << std::endl;
}
