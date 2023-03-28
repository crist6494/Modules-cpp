/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/28 19:40:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <string>
#include "contact.hpp"

class Phonebook{
	private:
		Contact	contacts[8];
		int		n_contacts;
	public:
		Phonebook();
		void	add_contact();
		void	print_phonebook();
};  

#endif