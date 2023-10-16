/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:00:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 19:10:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void print_dates(Bureaucrat& bc, AForm *form)
{
	std::cout << std::endl;
	std::cout << bc;
	std::cout << "---------------------------\n";
	std::cout << *form;
	std::cout << "---------------------------\n";
	bc.signForm(*form);
	std::cout << std::endl;
	bc.executeForm(*form);
	std::cout << "---------------------------\n";
	delete form;
	form = nullptr;
	std::cout << std::endl;
}

int main()
{
	try
	{
		Bureaucrat b("Pepe", 1);
		AForm *f = nullptr;
		Intern i;
		
		f = i.makeForm("RobotomyRequestForm", "Pedro");
		print_dates(b, f);
		f = i.makeForm("ShrubberyCreationForm", "Juan");
		print_dates(b, f);
		f = i.makeForm("PresidentialPardonForm", "Cristian");
		print_dates(b, f);
		f = i.makeForm("Mal", "Cristian");
		if(f)
			print_dates(b, f);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
	return 0;
}