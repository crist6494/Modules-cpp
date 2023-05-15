/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:37:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 17:32:37 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	std::cout<<"Default constructor called for ClavTrap: NO NAME"<<std::endl;

}

ClapTrap::ClapTrap(std::string name)
	: _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	this->_name= name;
	std::cout<<"Constructor with 1 parameter <string> called from ClapTrap: " << this->_name <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	std::cout<<"Copy constructor called from ClapTrap"<<std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(){
	std::cout<<"Destructor called from ClapTrap: " << this->_name <<std::endl;
}

void ClapTrap::printDates() const
{
	std::cout << "ClapTrap " << this->_name << ": " << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is died can not attack!" << std::endl;
		return ;
	}
	if(this->_energypoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " does not have energy for attack!" << std::endl;
		return ;
	}
	std::cout<<"ClapTrap "<< this->_name <<" attacks " << target <<", causing "<< this->getAttackDamage() <<" points of damage!" << std::endl;
	this->_energypoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is died!" << std::endl;
		return ;
	}
	if(this->_hitpoints >= amount)
		this->_hitpoints -= amount;
	else
		this->_hitpoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->_hitpoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is died can not be repaired!" << std::endl;
		return ;
	}
	if(this->_energypoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " does not have energy for be repaired!" << std::endl;
		return ;
	}
	std::cout<<"ClapTrap "<< this->_name <<" is repaired by: " << amount << " points" <<std::endl;
	this->_hitpoints += amount;
	this->_energypoints--;
}

std::string ClapTrap::getName() const
{
	return(this->_name);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return(this->_attackdamage);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	std::cout<<"Assignation operator called from ClapTrap"<<std::endl;
	this->_name = obj._name;
	this->_attackdamage = obj._attackdamage;
	this->_energypoints = obj._energypoints;
	this->_hitpoints = obj._hitpoints;
	return *this;
}