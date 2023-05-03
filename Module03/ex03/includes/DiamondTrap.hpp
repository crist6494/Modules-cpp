/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/03 23:21:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap, public virtual ClapTrap
{
	private:
		std::string _name;
	public:
		//DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		void Diamond_Dates() const;
		//DiamondTrap(const DiamondTrap& src);
		
		//DiamondTrap& operator=(const DiamondTrap& obj);
		
};

#endif