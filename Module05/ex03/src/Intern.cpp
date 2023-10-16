/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:58:47 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 12:02:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Default constructor called from Intern"<<std::endl;
}

Intern::~Intern()
{
	std::cout<< RED <<"Destructor called from Intern"<<std::endl << RESET;
}

Intern::Intern(const Intern& cpy)
{
	std::cout << YELLOW <<"Copy constructor called from Itern" <<std::endl << RESET;
	*this = cpy;
}

Intern& Intern::operator=(const Intern& src)
{
	std::cout << YELLOW <<"Assignation operator called from AForm"<<std::endl << RESET;
	if(this = &src)
		return *this;
	return *this;
}
