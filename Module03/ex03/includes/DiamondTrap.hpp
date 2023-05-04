/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 19:40:02 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& src);
		
		void Diamond_Dates() const;
		void whoAmI();
		void attack(const std::string& target);
		
		DiamondTrap& operator=(const DiamondTrap& obj);
		
};

#endif