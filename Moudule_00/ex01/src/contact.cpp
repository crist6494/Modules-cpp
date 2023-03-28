/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:53 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/28 20:18:41 by cmorales         ###   ########.fr       */
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

int Contact::set_fields()
{
	for(int i = 0; i < 5; i++){
		std::cout<<fields[i]<<": ";
		std::getline(std::cin, fields_contacts[i]);
		if(fields_contacts[i].empty())
		{
			std::cout<<"None of the fields can be left empty"<<std::endl;
			return (1);
		}
	}
	return(0);
}

void Contact::print_contacts()
{
	for(int i = 0; i < 5; i++){
		std::cout<<" |"<<fields_contacts[i];
	}
	std::cout<<"\n";
}