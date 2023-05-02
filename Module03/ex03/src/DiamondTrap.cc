/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 23:09:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/02 23:28:05 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* DiamondTrap::DiamondTrap()
	ClapTrap()
{
	
} */

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name")
{
	this->_name = name;
}