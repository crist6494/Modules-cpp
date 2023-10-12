/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:07:24 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 20:16:23 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm()
{
	std::cout<<"Default constructor called from ShrubberyCreationForm"<<std::endl;
}

/* ShrubberyCreationForm::ShrubberyCreationForm(std::string name,int gradeSign, int gradeExecute)
	:_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout<<"Default constructor called from ShrubberyCreationForm: " << this->_name <<std::endl;
	if((this->_gradeExecute < 1) || (this->_gradeSign < 1))
		throw ShrubberyCreationForm::GradeTooHighException();
	if((this->_gradeExecute > 150) || (this->_gradeSign > 150))
		throw ShrubberyCreationForm::GradeTooLowException();
	std::cout << GREEN << "Object built correctly: "<< this->getName() << std::endl << RESET;
} */

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< RED <<"Destructor called from ShrubberyCreationForm: " << this->_name <<std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
	:_name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute)
{
	std::cout << YELLOW <<"Copy constructor called, copy obj: " << cpy._name <<std::endl << RESET;
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << YELLOW <<"Assignation operator called, assigns the object: " << src._name <<std::endl << RESET;
	if(this == &src)
		return *this;
	this->_signed = src._signed;
	return *this;
}
