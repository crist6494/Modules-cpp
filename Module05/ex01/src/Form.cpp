/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/11 20:25:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	std::cout<<"Default constructor called from Form"<<std::endl;
}

Form::~Form()
{
	std::cout<<"Destructor called from Form"<<std::endl;
}

Form::Form(const Form& cpy)
	:_name(cpy._name)
{
	*this = cpy;
	std::cout<<"Copy constructor called from Form"<<std::endl;
}

Form& Form::operator=(const Form src)
{
	std::cout<<"Assignation operator called from Form"<<std::endl;
	if(this = &src)
		return *this;
	this->_grade_execute = src._grade_execute;
	this->_grade_range = src._grade_range;
	this->_signed = src._signed;
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


const std::string Form::getName()
{
	return this
}
const int Form::getGradeSign()
{
	return this
}
const Form::int _grade_execute getGradeExecute
{
	return this
}
bool Form::_signed getSigned
{
	return this
}