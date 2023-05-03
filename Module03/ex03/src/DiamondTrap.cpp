/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/03 23:17:06 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* DiamondTrap::DiamondTrap()
	ClapTrap()
{
	
} */

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name")
{
	this->_name = name;
}

DiamondTrap::~DiamondTrap()
{
} 

void DiamondTrap::Diamond_Dates() const
{
	std::cout << "Diamond " << this->_name << ": " << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}
