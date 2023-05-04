/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:18 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 18:36:08 by cmorales         ###   ########.fr       */
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
		static const unsigned int hitpoints_ft = 100;
        static const unsigned int energypoints_ft = 100;
        static const unsigned int attackdamage_ft = 30;
		FragTrap();
		~FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& src);
		
		FragTrap& operator=(const FragTrap& obj);
		
		void FragTrap_Dates() const;
		void highFivesGuys();
};

#endif