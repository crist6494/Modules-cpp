/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:21:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/28 20:42:22 by cmorales         ###   ########.fr       */
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

/* void Phonebook::print_contacts()
{
	if(contacts)
} */