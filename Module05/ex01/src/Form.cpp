/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 12:01:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name(""),_signed(false), _gradeExecute(0), _gradeSign(0)
{
	std::cout<<"Default constructor called from Form"<<std::endl;
}

Form::Form(std::string name, int gradeExecute, int gradeSign)
	:_name(name), _signed(false), _gradeExecute(gradeExecute), _gradeSign(gradeSign)
{
	std::cout<<"Default constructor called from Form: " << this->_name <<std::endl;
	if((this->_gradeExecute < 1) || (this->_gradeSign < 1))
		throw Form::GradeTooHighException();
	if((this->_gradeExecute > 150) || (this->_gradeSign > 150))
		throw Form::GradeTooLowException();
	std::cout << GREEN << "Object built correctly: "<< this->getName() << std::endl << RESET;
}

Form::~Form()
{
	std::cout<< RED <<"Destructor called from Form"<<std::endl << RESET;
}

Form::Form(const Form& cpy)
	:_name(cpy._name), _gradeExecute(cpy._gradeExecute), _gradeSign(cpy._gradeSign)
{
	std::cout << YELLOW <<"Copy constructor called, copy obj: " << cpy._name <<std::endl << RESET;
	*this = cpy;
}

Form& Form::operator=(const Form& src)
{
	std::cout << YELLOW <<"Assignation operator called, assigns the object: " << src._name <<std::endl << RESET;
	if(this == &src)
		return *this;
	this->_signed = src._signed;
	return *this;
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "<Form> Grade is too high (1 is the highest)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "<Form> Grade is too low (150 is the lowest)";
}


std::string Form::getName()const
{
	return this->_name;
}
int Form::getGradeSign()const
{
	return this->_gradeSign;
}
int Form::getGradeExecute()const
{
	return this->_gradeExecute;
}
bool Form::getSigned()const
{
	return this->_signed;
}


std::ostream& operator<<(std::ostream& out, const Form& src)
{
	out << CYAN << "Form name: " << src.getName() << std::endl;
	out << CYAN << "Signed: " << src.getSigned() << std::endl;
	out << CYAN << "GradeExecute: " << src.getGradeExecute() << std::endl;
	out << CYAN << "GradeSign: " << src.getGradeSign() << std::endl << RESET;
	return out;
}
