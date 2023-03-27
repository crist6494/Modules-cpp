/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/27 20:43:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	std::string	cmd;
	
	while(cmd != "EXIT")
	{
		std::cout<<"Enter a command: ";
		std::getline(std::cin, cmd);
		std::cout<<cmd<<std::endl;
		if(cmd == "ADD")
			std::cout<<"ADD"<<std::endl;
		else if(cmd == "SEARCH")
			std::cout<<"SEARCH"<<std::endl;
		else
			std::cout<<"Please enter: ADD, SEARCH or EXIT"<<std::endl;
		if(cmd == "EXIT")
			return (1);
	}
}