/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:00:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/14 13:41:40 by cmorales         ###   ########.fr       */
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
		//AForm f("Form", 45, 32);
		ShrubberyCreationForm s("Juan");
		RobotomyRequestForm d("Felipe");
		PresidentialPardonForm p("Luis");
		
		//std::cout << f;
		std::cout << s;
		std::cout << "------------\n";
		std::cout << d;
		std::cout << "------------\n";
		std::cout << p;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
}