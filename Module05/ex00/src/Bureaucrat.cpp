/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/10 20:14:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout<<"Default constructor called from Bureaucrat"<<std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name), _grade(grade)
{
	std::cout<<"Default constructor with (parameters) called from Bureaucrat"<<std::endl;
	try{
		if(this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if(this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Destructor called from Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	:_name(src._name), _grade(src._grade)
{
	std::cout<<"Copy constructor called from Bureaucrat"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if(this == &src)
		return *this;
	std::cout<<"Assignation operator called from Bureacrat"<<std::endl;
	this->_grade = src._grade;
	return *this;
}



const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (1 is the highest)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (150 is the lowest)";
}



const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}