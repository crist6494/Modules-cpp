/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:26:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:AAnimal()
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
	:AAnimal(src)
{
	std::cout<<"Copy constructor called from Cat" <<std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout<<"Assignation operator called from Cat" <<std::endl;
	AAnimal::operator=(src);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meauww Meauww !!!" << std::endl;
}

