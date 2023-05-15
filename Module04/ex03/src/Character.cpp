/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:11:47 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 20:30:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character(std::string const &name)
	:_name(name);
{
	std::cout << "Constructor with 1 parameter <string> called from AMateria: " << this->name << std::endl;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character()
{
	std::cout << "Default constructor called from Character: NO NAME"<<std::endl;
}

Character::~Character()
{
	std::cout << "Destructor called from Character: " << this->_name << std::endl;
}

Ice::Character(const Character& src)
{
	std::cout << "Copy constructor called from Character: " << this->_name <<std::endl;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = src.inventory[i];
	}
}
		
Character& Character::operator=(const Character& src)
{
	std::cout << "Assignation operator called from Character: " << this->_name << std::endl;
	this->_name = src._name;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = src.inventory[i];
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for(int i = 0; i < 4; i++){
		if(this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			 std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
			return ;
		}
	}
    std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
}