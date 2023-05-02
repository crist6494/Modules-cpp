/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:36:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 18:38:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitpoints;
		unsigned int _energypoints;
		unsigned int _attackdamage;
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& src);
		
		void printDates() const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName() const;
		
		unsigned int getAttackDamage() const;
		
		ClapTrap& operator=(const ClapTrap &obj);
};

#endif