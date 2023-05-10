/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 18:27:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	this->_type = "Cat";
	std::cout<<"Default constructor called from Cat: NO NAME"<<std::endl;
}

Cat::Cat(const std::string& name) :Animal(name)
{
	this->_type = "Cat";
	this->_name = name;
	std::cout<<"Constructor with parameters called from Cat: "<< this->_name <<std::endl;
}

Cat::~Cat()
{
	std::cout<<"Destructor called from Cat" <<std::endl;
}

Cat::Cat(const Cat& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called from Cat" <<std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout<<"Assignation operator called from Cat" <<std::endl;
	Animal::operator=(src);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meauww Meauww !!!" << std::endl;
}

