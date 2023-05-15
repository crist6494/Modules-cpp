/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:30:51 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 17:19:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap p1("Cristian");
	ClapTrap p2("Juan");
	ClapTrap p3("Manu");

	p1.printDates();
	std::cout << std::endl;
	p2.printDates();
	std::cout << std::endl;
	p3.printDates();
	std::cout << std::endl;
	
	p1.attack(p2.getName());
	p2.attack(p1.getName());
	p1.beRepaired(7);
	p2.beRepaired(7);
	p3.beRepaired(20);
	p3.takeDamage(6);
	std::cout << std::endl;

	std::cout << "After the attacks" << std::endl;
	p1.printDates();
	std::cout << std::endl;
	p2.printDates();
	std::cout << std::endl;
	p3.printDates();
	std::cout << std::endl;

	return 0;
}