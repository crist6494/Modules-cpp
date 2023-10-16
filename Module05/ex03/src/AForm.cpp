/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:58:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 19:45:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name(""),_signed(false), _gradeSign(0), _gradeExecute(0)
{
	std::cout<<"Default constructor called from AForm"<<std::endl;
}

AForm::AForm(std::string name,int gradeSign, int gradeExecute)
	:_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout<<"Default constructor called from AForm: " << this->_name <<std::endl;
	if((this->_gradeExecute < 1) || (this->_gradeSign < 1))
		throw AForm::GradeTooHighException();
	if((this->_gradeExecute > 150) || (this->_gradeSign > 150))
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "Object form built correctly: "<< this->getName() << std::endl << RESET;
}

AForm::~AForm()
{
	std::cout<< RED <<"Destructor called from AForm: " << this->_name <<std::endl << RESET;
}

AForm::AForm(const AForm& cpy)
	:_name(cpy._name), _gradeSign(cpy._gradeSign), _gradeExecute(cpy._gradeExecute)
{
	std::cout << YELLOW <<"Copy constructor called from AForm, copy obj: " << cpy._name <<std::endl << RESET;
	*this = cpy;
}

AForm& AForm::operator=(const AForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from AForm, assigns the object: " << src._name <<std::endl << RESET;
	if(this == &src)
		return *this;
	this->_signed = src._signed;
	return *this;
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade is too high (1 is the highest)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade is too low (150 is the lowest)";
}

const char* AForm::GradeSignedException::what() const throw()
{
	return " is not signed";
}


std::string AForm::getName()const
{
	return this->_name;
}
int AForm::getGradeSign()const
{
	return this->_gradeSign;
}
int AForm::getGradeExecute()const
{
	return this->_gradeExecute;
}
bool AForm::getSigned()const
{
	return this->_signed;
}


std::ostream& operator<<(std::ostream& out, const AForm& src)
{
	out << CYAN << "AForm name: " << src.getName() << std::endl;
	out << CYAN << "Signed: " << src.getSigned() << std::endl;
	out << CYAN << "GradeSign: " << src.getGradeSign() << std::endl;
	out << CYAN << "GradeExecute: " << src.getGradeExecute() << std::endl << RESET;
	return out;
}


void AForm::beSigned(const Bureaucrat& bc)
{
	if(bc.getGrade() <= this->getGradeSign())
	{
		this->_signed = true;
		std::cout <<MAGENTA << this->getName() << " is signed by " << bc.getName() << std::endl << RESET;
	}
	else
		throw std::exception();
}

