/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:28:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 21:00:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

 RobotomyRequestForm:: RobotomyRequestForm()
	: AForm(), _target("")
{
	std::cout<<"Default constructor called from RobotomyRequestForm"<<std::endl;
}

 RobotomyRequestForm:: RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", 145, 137), _target(target)
{
	std::cout<<"Default constructor called from RobotomyRequestForm: " << this->getName() <<std::endl;
}


 RobotomyRequestForm::~ RobotomyRequestForm()
{
	std::cout<< RED <<"Destructor called from RobotomyRequestForm: " << this->getName() <<std::endl << RESET;
}

 RobotomyRequestForm:: RobotomyRequestForm(const  RobotomyRequestForm& cpy)
	:AForm(cpy)
{
	std::cout << YELLOW <<"Copy constructor called from RobotomyRequestForm, copy obj: " << cpy.getName() <<std::endl << RESET;
	*this = cpy;
}

 RobotomyRequestForm&  RobotomyRequestForm::operator=(const  RobotomyRequestForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from RobotomyRequestForm, assigns the object: " << src.getName() <<std::endl << RESET;
	AForm::operator=(src);
	if(this == &src)
		return *this;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	int randNumber;
	
	if(this->getSigned() == false)
		throw AForm::GradeTooLowException();
	if(executor.getGrade() >= this->getGradeExecute())
		throw AForm::GradeTooLowException();
	
	std::cout << BLUE << "Drilling noises..." << std::endl << RESET;
	std::srand((time(0))); 
	randNumber = rand();
	if(randNumber % 2 == 0)
		std::cout << BLUE << this->getTarget() << "has been robotomized successfully" << std::endl << RESET;
	else
		std::cout << BLUE << "the robotomy failed." << std::endl << RESET;

}