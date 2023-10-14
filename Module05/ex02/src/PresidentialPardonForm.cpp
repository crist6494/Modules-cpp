/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:36:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:39:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

 PresidentialPardonForm:: PresidentialPardonForm()
	: AForm()
{
	std::cout<<"Default constructor called from  PresidentialPardonForm"<<std::endl;
}

 PresidentialPardonForm:: PresidentialPardonForm(std::string target)
	:AForm(target, 25, 5)
{
	std::cout<<"Default constructor called from  PresidentialPardonForm: " << this->getName() <<std::endl;
}


 PresidentialPardonForm::~ PresidentialPardonForm()
{
	std::cout<< RED <<"Destructor called from  PresidentialPardonForm: " << this->getName() <<std::endl << RESET;
}

 PresidentialPardonForm:: PresidentialPardonForm(const  PresidentialPardonForm& cpy)
	:AForm(cpy)
{
	std::cout << YELLOW <<"Copy constructor called from  PresidentialPardonForm, copy obj: " << cpy.getName() <<std::endl << RESET;
	*this = cpy;
}

 PresidentialPardonForm&  PresidentialPardonForm::operator=(const  PresidentialPardonForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from  PresidentialPardonForm, assigns the object: " << src.getName() <<std::endl << RESET;
	AForm::operator=(src);
	if(this == &src)
		return *this;
	return *this;
}
