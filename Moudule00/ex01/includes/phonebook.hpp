/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 17:28:11 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include "contact.hpp"
# include <iomanip>

# define RESET			"\033[0m"
# define MAGENTA		"\033[35m"	
# define BOLDCYAN		"\033[1m\033[36m"

class Phonebook{
	private:
		Contact	contacts[8];
		int		n_contacts;
	public:
		Phonebook();
		~Phonebook();
		void	add_contact();
		void	print_contact_table();
		void	print_num_contact(int n);
};  

#endif