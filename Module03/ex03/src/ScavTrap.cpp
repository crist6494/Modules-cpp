/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:27:48 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 19:58:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout<<"Default constructor called from ScavTrap: NO NAME"<<std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout<<"Constructor with 1 parameter <string> called from ScavTrap: " << this->_name <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src)
	: ClapTrap(src)
{
	std::cout<<"Copy constructor called from ScavTrap"<<std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(){
	std::cout<<"Destructor called from ScavTrap: " << this->_name <<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	std::cout<<"Assignation operator called from ScavTrap"<<std::endl;
	ClapTrap::operator=(obj);
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::ScavTrap_Dates() const
{
	std::cout << "ScavTrap " << this->_name << ": " << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}