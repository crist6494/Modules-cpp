/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:29:34 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 11:36:21 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout<<"Default constructor called from WrongCat: NO NAME"<<std::endl;
}

WrongCat::~WrongCat()
{
	std::cout<<"Destructor called from WrongCat" <<std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
	:WrongAnimal(src)
{
	std::cout<<"Copy constructor called from WrongCat" <<std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout<<"Assignation operator called from WrongCat" <<std::endl;
	WrongAnimal::operator=(src);
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meauww Meauww !!!" << std::endl;
}
