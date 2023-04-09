/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:48:40 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/09 16:54:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
