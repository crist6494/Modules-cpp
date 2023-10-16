/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:29:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 19:48:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat j("Juan", 1);
		Form f("Google form", 1, 60);
		std::cout << "------------\n";
		std::cout << j;
		std::cout << "------------\n";
		std::cout << f;
		std::cout << "------------\n";
		j.signForm(f);
		std::cout << "------------\n";
	}
	catch(const Bureaucrat::GradeTooLowException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
	}
	return 0;
}