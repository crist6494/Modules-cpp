/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:00:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 11:52:24 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void print_dates(Bureaucrat& bc, AForm& form)
{
	std::cout << std::endl;
	std::cout << bc;
	std::cout << "---------------------------\n";
	std::cout << form;
	std::cout << "---------------------------\n";
	bc.signForm(form);
	std::cout << std::endl;
	bc.executeForm(form);
	std::cout << "---------------------------\n";
	std::cout << std::endl;
}


int main()
{
	try
	{
		Bureaucrat b("Manu", 44);
		ShrubberyCreationForm s("Juan");
		RobotomyRequestForm d("Felipe");
		PresidentialPardonForm p("Luis");

		print_dates(b, s);
		print_dates(b, d);
		print_dates(b, p);
	}
	catch(const AForm::GradeTooHighException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const AForm::GradeTooLowException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}