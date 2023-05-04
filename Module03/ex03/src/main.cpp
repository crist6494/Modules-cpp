/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:51 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/04 20:07:56 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap p1("Cristian");
	
	std::cout << std::endl;
	p1.Diamond_Dates();
	std::cout << std::endl;
	p1.attack("Juan");
	std::cout << std::endl;
	p1.whoAmI();
	std::cout << std::endl;
	DiamondTrap p2(p1);
	std::cout << std::endl;
	p2.Diamond_Dates();
	std::cout << std::endl;
	return 0;
}