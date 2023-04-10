/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/10 17:29:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: _weapon(weapon)
{
	this->name = name;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout<< this->name << " attacks with his " << this->_weapon.getType() << std::endl;
}