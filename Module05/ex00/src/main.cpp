/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 12:03:04 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat j("Juan", 150);
		Bureaucrat c("Cristobal", 2);
		std::cout << j;
		std::cout << c;
		j.decrementGrade(1);
		std::cout << j;
		c.incrementGrade(1);
		std::cout << c;
		Bureaucrat d(j);
		std::cout << d;
		Bureaucrat e;
		e = c;
		std::cout << e;
	}
	catch(const Bureaucrat::GradeTooLowException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	catch(const Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << RED << "Error: " << exception.what() << std::endl << RESET;
	}
	return 0;
}