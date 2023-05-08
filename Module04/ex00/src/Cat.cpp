/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:43:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/08 20:02:39 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	std::cout<<"Default constructor called from Cat: NO NAME"<<std::endl;
}

Cat::~Cat()
{
	std::cout<<"Destructor called from Cat " <<std::endl;
}

Cat::Cat(const Cat& src)
	:Animal(src)
{
	std::cout<<"Copy constructor called fromCatl"<<std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout<<"Assignation operator called from Cat"<<std::endl;
	Animal::operator=(src);
	return *this;
}
