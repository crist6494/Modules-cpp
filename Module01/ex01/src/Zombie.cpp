/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:30:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/14 16:39:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	this->announce();
}

Zombie::~Zombie()
{
	std::cout<< this->name <<" has been destroyed"<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout<< this->name <<": BraiiiiiiinnnzzzZ..."<< std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}