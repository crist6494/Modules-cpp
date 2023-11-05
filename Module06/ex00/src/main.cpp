/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:40:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/05 23:35:11 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		try
		{
			ScalarConverter::convert(av[1]);
		}
		catch (const std::out_of_range& e)
		{
        	std::cerr << RED << "Error: Overflow value" << std::endl << RESET;
		}
		catch(std::exception& e)//Añadir exception fuera de rango
		{
			std::cerr << RED << "Not type found" << RESET << std::endl;
		}
		return 0;
	}
	std::cerr << RED << "Error: Bad arguments" << std::endl << RESET;
	std::cout << MAGENTA << "Usage: ./scalaConverter <string>" << std::endl << RESET;
	return 1;
}