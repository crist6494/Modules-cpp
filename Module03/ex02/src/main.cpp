/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:51 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 22:36:55 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap p1("Cristian");
	FragTrap p2("Juan");
	FragTrap p3("Manu");

	std::cout << std::endl;
	p1.FragTrap_Dates();
	std::cout << std::endl;
	p2.FragTrap_Dates();
	std::cout << std::endl;
	p3.FragTrap_Dates();
	std::cout << std::endl;

	for(int i = 0; i < 9; i++){
		p1.attack(p2.getName());
		p2.takeDamage(1);
	}
	p1.attack(p2.getName());
	p2.attack(p1.getName());
	p1.beRepaired(7);
	p2.beRepaired(7);
	p3.beRepaired(20);
	std::cout << std::endl;

	std::cout << "After the attacks" << std::endl;
	std::cout << std::endl;
	p1.FragTrap_Dates();
	std::cout << std::endl;
	p2.FragTrap_Dates();
	std::cout << std::endl;
	p3.FragTrap_Dates();
	std::cout << std::endl;

	std::cout << std::endl;
	p1.highFivesGuys();
	p2.highFivesGuys();
	p3.highFivesGuys();
	std::cout << std::endl;
	return 0;
}