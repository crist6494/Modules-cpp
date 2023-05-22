/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:24:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/22 20:51:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure")
{
	std::cout << "Default constructor called from Cure" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Destructor called from Cure" << std::endl;
}

Cure::Cure(const Cure& src)
	:AMateria(src)
{
	std::cout << "Copy constructor called from Cure" <<std::endl;
	*this = src;
}
		
Cure& Cure::operator=(const Cure& src)
{
	std::cout << "Assignation operator called from Cure" << std::endl;
	AMateria::operator=(src);
	return *this;
}

AMateria* Cure::clone() const
{
	Cure *cure = new Cure();
	
	return cure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " ’s wounds *" << std::endl;
}

