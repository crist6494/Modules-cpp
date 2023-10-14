/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:00:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 21:12:49 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b("Manu", 2);
		//AForm f("Form", 45, 32);
		ShrubberyCreationForm s("Juan");
		RobotomyRequestForm d("Felipe");
		PresidentialPardonForm p("Luis");
		//std::cout << f;
		std::cout << "------------\n";
		std::cout << s;
		std::cout << "------------\n";
		std::cout << d;
		std::cout << "------------\n";
		std::cout << p;
		std::cout << "------------\n";
		b.signForm(s);
		b.executeForm(s);
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