/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:30:36 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/14 16:40:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int n = 5;
	Zombie *zb_horde = zombieHorde(n, "Pepe");
	
	for(int i = 0; i < n; i++){
		zb_horde[i].announce();
	}
	delete[] zb_horde;
	return 0;
}
