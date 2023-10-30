/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:40:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/29 18:13:49 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac == 2)
	{
		ScalarConverter::convert(av[1]);
		return 0;
	}
	std::cerr << RED << "Error: Bad arguments" << std::endl << RESET;
	std::cout << CYAN << "Usage: ./scalaConverter (string)" << std::endl << RESET;
	return 1;
}