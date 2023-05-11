/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:51:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	std::cout << "Constructor with 1 parameter <string> called from AMateria: " << std::endl;
	this->_type = type;
}

AMateria::AMateria()
{
	std::cout << "Default constructor called from AMateria" < <std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called from AMateria" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << "Copy constructor called from AMateria" <<std::endl;
	*this = src;
}

AMateria& AMateria::operator=(const AMateria& src)
{
	std::cout << "Assignation operator called from Amateria" << std::endl;
	this->_type = src._type;
	return  *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}
