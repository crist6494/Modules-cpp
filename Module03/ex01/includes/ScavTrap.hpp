/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:26:40 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 18:47:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& src);
		
		ScavTrap& operator=(const ScavTrap& obj);
		
		void guardGate();
		void ScavTrap_Dates() const;
		
};

#endif