/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:55 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 17:27:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

# define RESET			"\033[0m"
# define MAGENTA		"\033[35m"	
# define BOLDCYAN		"\033[1m\033[36m"


class Contact{
	private:
		std::string	fields[5];
		std::string	fields_contacts[5];
	public:
		Contact();
		~Contact();
		int		set_fields();
		void	print_fields_table();
		void	print_data_table();
		void	print_contacts();
};
 
#endif