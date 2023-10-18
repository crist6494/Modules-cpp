/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:53 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 17:28:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){
	fields[0] = "First name";
	fields[1] = "Last name";
	fields[2] = "Nickname";
	fields[3] = "Phone number";
	fields[4] = "Darkest secret";
}

Contact::~Contact(){
}

int Contact::set_fields()
{
	for(int i = 0; i < 5; i++){
		std::cout<< fields[i]<<": ";
		std::getline(std::cin, fields_contacts[i]);
		if(fields_contacts[i].empty())
		{
			std::cout<< "None of the fields can be left empty"<<std::endl;
			return (1);
		}
	}
	return(0);
}

void Contact::print_fields_table()
{
	for(int i = 0; i < 5; i++)
	{
		if(fields[i].length() > 10)
			std::cout<< BOLDCYAN<<fields[i].substr(0, 9)<< RESET<< ".|";
		else
			std::cout<< BOLDCYAN<< std::setw(10)<< fields[i] <<RESET << "|";
	}
}

void Contact::print_data_table()
{
	std::cout<<"|";
	for(int i = 0; i < 5; i++){
		if(fields_contacts[i].length() > 10)
			std::cout<< fields_contacts[i].substr(0, 9)<< ".|";
		else
			std::cout<< std::setw(10)<< fields_contacts[i] << "|";
	}
	std::cout<<std::endl;
}

void Contact::print_contacts()
{
	for(int i = 0; i < 5; i++){
		std::cout<< fields[i] + ": " + fields_contacts[i]<<std::endl;
	}
	std::cout<< std::endl;
}
