/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:55 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/29 00:34:58 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

class Contact{
	private:
		std::string	fields_contacts[5];
	public:
		std::string	fields[5];
		Contact();
		int		set_fields();
		void	print_contacts();
		void	print_data_table();
};
 
#endif