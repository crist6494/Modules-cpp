/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:28:03 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:32:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

 RobotomyRequestForm:: RobotomyRequestForm()
	: AForm()
{
	std::cout<<"Default constructor called from  RobotomyRequestForm"<<std::endl;
}

 RobotomyRequestForm:: RobotomyRequestForm(std::string target)
	:AForm(target, 145, 137)
{
	std::cout<<"Default constructor called from  RobotomyRequestForm: " << this->getName() <<std::endl;
}


 RobotomyRequestForm::~ RobotomyRequestForm()
{
	std::cout<< RED <<"Destructor called from  RobotomyRequestForm: " << this->getName() <<std::endl << RESET;
}

 RobotomyRequestForm:: RobotomyRequestForm(const  RobotomyRequestForm& cpy)
	:AForm(cpy)
{
	std::cout << YELLOW <<"Copy constructor called from  RobotomyRequestForm, copy obj: " << cpy.getName() <<std::endl << RESET;
	*this = cpy;
}

 RobotomyRequestForm&  RobotomyRequestForm::operator=(const  RobotomyRequestForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from  RobotomyRequestForm, assigns the object: " << src.getName() <<std::endl << RESET;
	AForm::operator=(src);
	if(this == &src)
		return *this;
	return *this;
}
