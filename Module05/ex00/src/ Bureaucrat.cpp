/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Bureaucrat.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/09 20:53:02 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	this->_name = "";
	this->_grade = 0;
	std::cout<<"Default constructor called from Bureaucrat"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Destructor called from Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	if(this == &src)
		return *this;
	std::cout<<"Copy constructor called from Bureaucrat"<<std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout<<"Assignation operator called from Bureacrat"<<std::endl;
	this->_name = src._name;
	this->_grade = src._grade;
	return *this;
}