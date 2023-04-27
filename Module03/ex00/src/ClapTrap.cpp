/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:37:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/27 12:12:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) 
	: _hitpoints(10), _energypoints(10), _attackdamage(0)
{
	this->_name= name;
	std::cout<<_hitpoints;
	}

ClapTrap::~ClapTrap(){
}