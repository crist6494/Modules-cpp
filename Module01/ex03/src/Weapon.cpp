/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/09 17:25:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	const std::string &ref_type = this->type;
	
	return ref_type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}