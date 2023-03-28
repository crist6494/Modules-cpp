/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:33:55 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/28 19:44:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

class Contact{
	private:
		std::string	fields[5];
	public:
		std::string	fields_contacts[5];
		Contact();
		int		set_fields();
		void	print_contacts();
};
 
#endif