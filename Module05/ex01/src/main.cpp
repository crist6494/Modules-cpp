/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:29:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 12:03:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Form f("Felipe", 1, 6);
		Form c(f);
		std::cout << f;
		std::cout << "------------\n";
		std::cout << c;
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