/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:21:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 17:41:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(){
	n_contacts = 0;
}

Phonebook::~Phonebook(){
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
	if(n >= 8)
		n = 8;
	std::cout<< "--------------------------------------------------------\n";
	std::cout<<"|";
	contacts[0].print_fields_table();
	std::cout<<std::endl;	
	for(int i = 0; i < n; i++){
		std::cout << "--------------------------------------------------------\n";
		contacts[i].print_data_table();
	}
	std::cout<< "--------------------------------------------------------\n";
}

void Phonebook::print_num_contact(int n)
{
	if(n <= 0 || n > 8 || n > n_contacts)
	{
		std::cout<<"Invalid index "<<std::endl;
		return ;
	}
	contacts[(n - 1) % 8].print_contacts();
}
