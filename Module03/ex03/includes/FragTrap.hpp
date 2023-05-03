/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/03 23:14:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		
		FragTrap& operator=(const FragTrap& obj);
		
		void FragTrap_Dates() const;
		void highFivesGuys();
};

#endif