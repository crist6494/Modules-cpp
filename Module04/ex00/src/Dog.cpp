/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/08 20:22:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	std::cout<<"Default constructor called from Cat: NO NAME"<<std::endl;
}

Dog::~Dog()
{
	std::cout<<"Destructor called from Cat " <<std::endl;
}

Dog::Dog(const Dog& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called fromCatl"<<std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout<<"Assignation operator called from Cat"<<std::endl;
	Animal::operator=(src);
	return *this;
}
