/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:51 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 22:13:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	ScavTrap p1("Cristian");
	ScavTrap p2("Juan");
	ScavTrap p3("Manu");

	std::cout << std::endl;
	p1.ScavTrap_Dates();
	std::cout << std::endl;
	p2.ScavTrap_Dates();
	std::cout << std::endl;
	p3.ScavTrap_Dates();
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
	p1.ScavTrap_Dates();
	std::cout << std::endl;
	p2.ScavTrap_Dates();
	std::cout << std::endl;
	p3.ScavTrap_Dates();
	std::cout << std::endl;

	std::cout << std::endl;
	p1.guardGate();
	p2.guardGate();
	p3.guardGate();
	std::cout << std::endl;
	
	ScavTrap p4(p2);
	std::cout <<p4.getName();
	std::cout <<p4.getAttackDamage();
	std::cout << std::endl;
	
	return 0;
}