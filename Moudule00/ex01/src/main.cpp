/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/13 20:10:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	Phonebook	pb;
	std::string	cmd;
	std::string	num;
	int			n;
	
	while(cmd != "EXIT")
	{
		std::cout<<"Enter a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (1);
		if(cmd == "EXIT")
			return (1);
		if(cmd == "ADD")
			pb.add_contact();
		else if(cmd == "SEARCH")
		{
			pb.print_contact_table();
			std::cout<<"Filter: ";
			std::getline(std::cin, num);
			if (std::cin.eof())
				return (1);
			if(num[0] >= '0' && num[0] <= '9' && num.size() < 10)
				n = std::stoi(num);
			else
				n = -1;
			pb.print_num_contact(n);
		}
		else
			std::cout<< "Please enter: ADD, SEARCH or EXIT"<< std::endl;
	}
}
