/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:24:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 19:53:02 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	:AMateria("cure");
{
	std::cout << "Default constructor called from Cure" < <std::endl;
}

virtual Cure::~Cure()
{
	std::cout << "Destructor called from Cure" << std::endl;
}

Cure::Cure(const Cure& src)
	:AMateria(src);
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
	
	return cure;4
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at <name> *" << std::endl;
}

