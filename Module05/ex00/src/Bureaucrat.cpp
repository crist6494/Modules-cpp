/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/10 10:51:18 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:_name("Manuel")
{
	this->_grade = 0;
	if(this->_grade == 0)
		throw 1;
	std::cout<<"Default constructor called from Bureaucrat"<<std::endl;
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

const std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}