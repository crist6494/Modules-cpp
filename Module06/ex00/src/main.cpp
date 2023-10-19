/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 20:40:42 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/19 20:50:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */


#include <iostream>

int main(int ac, char **av)
{
	(void)av;
	if(ac == 2)
	{
		std::cout << "Hola";
	}
	else
		std::cerr << RED << "Error: Only one parameter is possible" << std::endl << RESET;
}