/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:26:40 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 18:36:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
	public:
		static const unsigned int hitpoints_st = 100;
        static const unsigned int energypoints_st = 50;
        static const unsigned int attackdamage_st = 20;
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		
		ScavTrap& operator=(const ScavTrap& obj);
		
		void guardGate();
		void ScavTrap_Dates() const;
		
};
#endif
