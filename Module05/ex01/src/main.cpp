/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:29:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 19:54:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//Concepto LIFO, primer en añadir(push), ultimo en eliminar(POP)

int main()
{
	try
	{
		Bureaucrat j("Juan", 1);
		Form f("Google form", 19, 60);
		std::cout << "------------\n";
		std::cout << j;
		std::cout << "------------\n";
		std::cout << f;
		std::cout << "------------\n";
		j.signForm(f);
		std::cout << "------------\n";
	}
	catch(const Form::GradeTooHighException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const Form::GradeTooLowException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
}