/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:07:24 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm(), _target("")
{
	std::cout<<"Default constructor called from ShrubberyCreationForm"<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
	std::cout<<"Default constructor called from ShrubberyCreationForm: " << this->getName() <<std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<< RED <<"Destructor called from ShrubberyCreationForm: " << this->getName() <<std::endl << RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
	:AForm(cpy)
{
	std::cout << YELLOW <<"Copy constructor called from ShrubberyCreationForm, copy obj: " << cpy.getName() <<std::endl << RESET;
	*this = cpy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << YELLOW <<"Assignation operator called from ShrubberyCreationForm, assigns the object: " << src.getName() <<std::endl << RESET;
	AForm::operator=(src);
	if(this == &src)
		return *this;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}


void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	std::string filename;
	std::ofstream file;
	const char *filename_c;
	
	if(this->getSigned() == false)
		throw AForm::GradeSignedException();
	if(executor.getGrade() >= this->getGradeExecute())
		throw std::exception();
		
	filename = this->getTarget() + "_shrubbery";
	filename_c = filename.c_str();
	file.open(filename_c);
	if(!file.is_open())
		std::cerr << RED << "Error: File cannot be opened" << std::endl << RESET;
	file<<  "        >X<\n"
			"         A\n"
			"        d$b\n"
			"      .d\\$$b.\n"
			"    .d$i$$\\$$b.\n"
			"       d$$@b\n"
			"      d\\$$$ib\n"
			"    .d$$$\\$$$b\n"
			"  .d$$@$$$$\\$$ib.\n"
			"      d$$i$$b\n"
			"     d\\$$$$@$b\n"
			"  .d$@$$\\$$$$$@b.\n"
			".d$$$$i$$$\\$$$$$$b.\n"
			"        ###\n"
			"        ###\n"
			"        ###" 
				<< std::endl;
	file.close();
	std::cout << MAGENTA << this->getName() << " was built successfully" << std::endl << RESET; 
}