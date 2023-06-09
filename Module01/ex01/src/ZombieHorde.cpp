/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/14 16:39:55 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zb_horde = new Zombie[N];
	
	for(int i = 0; i < N; i++)
	{
		zb_horde[i].setName(name);
	}
	return zb_horde;
}