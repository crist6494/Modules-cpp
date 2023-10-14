/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:07:24 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:35:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
{
	std::cout<<"Default constructor called from ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm(target, 72, 45)
{
	std::cout<<"Default constructor called from ShrubberyCreationForm: " << this->getName() <<std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< RED <<"Destructor called from ShrubberyCreationForm: " << this->getName() <<std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
	:AForm(cpy)
{
	std::cout << YELLOW <<"Copy constructor called from ShrubberyCreationForm, copy obj: " << cpy.getName() <<std::endl << RESET;
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from ShrubberyCreationForm, assigns the object: " << src.getName() <<std::endl << RESET;
	AForm::operator=(src);
	if(this == &src)
		return *this;
	return *this;
}
