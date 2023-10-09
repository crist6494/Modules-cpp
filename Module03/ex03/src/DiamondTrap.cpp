/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/09 16:44:50 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:ClapTrap(), FragTrap(), ScavTrap()
{
	this->_hitpoints = FragTrap::hitpoints_ft;
    this->_energypoints = ScavTrap::energypoints_st;
    this->_attackdamage = FragTrap::attackdamage_ft;
	std::cout<<"Default constructor called from DiamondTrap: NO NAME"<<std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitpoints = FragTrap::hitpoints_ft;
    this->_energypoints = ScavTrap::energypoints_st;
    this->_attackdamage = FragTrap::attackdamage_ft;
	std::cout<<"Constructor with 1 parameter <string> called from DiamondTrap: " << this->_name <<std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"Destructor called from DiamondTrap: " << this->_name <<std::endl;
} 

DiamondTrap::DiamondTrap(const DiamondTrap& src)
	:ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout<<"Copy constructor called from DiamondTrap"<<std::endl;
	*this = src;
}

void DiamondTrap::Diamond_Dates() const
{
	std::cout << "Diamond: " << this->_name  << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am the DiamondTrap: " << this->_name << " and the ClapTrap name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	ClapTrap::operator=(obj);
	FragTrap::operator=(obj);
	ScavTrap::operator=(obj);
	std::cout<< "Assignation operator called from DiamondTrap" <<std::endl;
	return *this;
}