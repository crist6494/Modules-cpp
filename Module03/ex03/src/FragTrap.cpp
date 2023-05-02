/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:16:08 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 22:34:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap()
{
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout<<"Default constructor called from FragTrap: NO NAME"<<std::endl;
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout<<"Constructor with 1 parameter <string> called from FragTrap: " << this->_name <<std::endl;
}

FragTrap::FragTrap(const FragTrap& src)
	:ClapTrap(src)
{
	std::cout<<"Copy constructor called from FragTrap"<<std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout<<"Destructor called from FragTrap: " << this->_name <<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	std::cout<<"Assignation operator called from FragTrap"<<std::endl;
	ClapTrap::operator=(obj);
	return *this;	
}

void FragTrap::FragTrap_Dates() const
{
	std::cout << "FragTrap " << this->_name << ": " << std::endl;
	std::cout << "Hit points: " << this->_hitpoints << std::endl;
	std::cout << "Energy points: " << this->_energypoints << std::endl;
	std::cout << "Attack damage: " << this->_attackdamage << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Here Fragtrap: " << this->_name << " ,Wasapppppp!!??: ✋ " << std::endl;
	this->_energypoints--;
}