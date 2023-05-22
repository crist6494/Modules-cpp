/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:24:28 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/16 20:13:09 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	:AMateria("ice")
{
	std::cout << "Default constructor called from Ice" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor called from Ice" << std::endl;
}

Ice::Ice(const Ice& src)
	:AMateria(src)
{
	std::cout << "Copy constructor called from Ice" <<std::endl;
	*this = src;
}
		
Ice& Ice::operator=(const Ice& src)
{
	std::cout << "Assignation operator called from Ice" << std::endl;
	AMateria::operator=(src);
	return *this;
}

AMateria* Ice::clone() const
{
	Ice *ice = new Ice();

	return ice;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at" << target.getName() << "*"<< std::endl;
}
