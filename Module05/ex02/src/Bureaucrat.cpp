/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:30:14 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	:_name(""), _grade(0)
{
	std::cout<<"Default constructor called from Bureaucrat"<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	:_name(name), _grade(grade)
{
	std::cout<<"Default constructor with (parameters) called from Bureaucrat: " << this->_name<<std::endl;
		if(this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if(this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Object bureaucrat built correctly: "<< this->getName() << std::endl << RESET;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED <<"Destructor called from Bureaucrat: "<< this->_name <<std::endl <<RESET;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
	:_name(cpy._name)
{
	std::cout << YELLOW <<"Copy constructor called from Bureaucrat, copy obj: " << cpy._name <<std::endl << RESET;
	*this = cpy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << YELLOW <<"Assignation operator called form Bureaucrat, assigns the object: " << src._name <<std::endl << RESET;
	if(this == &src)
		return *this;
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



std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}



void Bureaucrat::incrementGrade(int amount)
{
	if((this->_grade - amount) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
	if((this->_grade + amount) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += amount;
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& src)
{
	out << CYAN << src.getName() << ", bureaucrat grade: " << src.getGrade() << std::endl << RESET;
	return out;
}


void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLUE << this->getName() << " signed " << form.getName() << RESET << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << RED << this->getName() << " couldn’t sign " << form.getName() << " because the bureaucrat's grade is lower than the form's grade to sign" << std::endl << RESET;
	}
}