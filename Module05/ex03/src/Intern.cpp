/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:58:47 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 19:47:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout<<"Default constructor called from Intern"<<std::endl;
	std::cout << GREEN << "Object intern built correctly"<< std::endl << RESET;
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
	if(this == &src)
		return *this;
	return *this;
}

static AForm* createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}


const char* Intern::IsNotFormException::what() const throw()
{
	return " is not a form";
}

static int getNameForm(std::string name)
{
	std::string forms[] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
	for (int i = 0; i < 3; i++)
	{
		if(name == forms[i])
			return i;
	}
	throw Intern::IsNotFormException();
}


AForm* Intern::makeForm(std::string nameForm,  std::string target)
{
	try
	{
		AForm* (*ptrfun[3])(std::string target) = {&createRobotomyRequestForm, &createShrubberyCreationForm, &createPresidentialPardonForm};
		AForm *form;
		form = ptrfun[getNameForm(nameForm)](target);
		return form;
	}
	catch(const Intern::IsNotFormException& e)
	{
		std::cerr << RED << "Error: " << nameForm << e.what() << std::endl << RESET; 
	}
	return nullptr;
}