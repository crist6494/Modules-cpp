/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:21:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 01:08:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(){
	n_contacts = 0;
}

void Phonebook::add_contact()
{
	Contact aux;
	if(aux.set_fields() == 0)
	{
		contacts[n_contacts % 8] = aux;
		n_contacts++;
	}
}

void Phonebook::print_contact_table()
{
	int n = n_contacts;
	std::cout<< "-------------------------------------------------------\n";
	std::cout<<"|";
	for(int i = 0; i < 5; i++){
		if(contacts[0].fields[i].length() > 10)
			std::cout<< BOLDCYAN<<contacts[0].fields[i].substr(0, 9)<< RESET<< "|.";
		else
		{
			std::cout<< BOLDCYAN<< std::setw(10)<< contacts[0].fields[i] <<RESET << "|";
		}
	}
	std::cout<<std::endl;	
	for(int i = 0; i < n;i++){
		std::cout << "-------------------------------------------------------\n";
		contacts[i].print_data_table();
	}
	std::cout<< "--------------------------------------------------------\n";
}