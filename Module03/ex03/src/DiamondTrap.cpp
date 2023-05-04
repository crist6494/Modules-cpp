/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 11:58:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* DiamondTrap::DiamondTrap()
	ClapTrap()
{
	
} */

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	FragTrap::_hitpoints = 100;
    ScavTrap::_energypoints = 50;
    FragTrap::_attackdamage = 30;
}

DiamondTrap::~DiamondTrap()
{
} 

void DiamondTrap::Diamond_Dates() const
{
	std::cout << "Diamond: " << this->_name  << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}
