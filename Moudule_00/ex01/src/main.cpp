/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:30:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 00:35:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	Phonebook pb;
	std::string	cmd;
	
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
			pb.print_contact_table();
		else
			std::cout<< "Please enter: ADD, SEARCH or EXIT"<< std::endl;
	}
}
			//std::cout<<std::endl;
			//std::cout<<c1.fields_contacts.length;
			//c1.print_contacts();