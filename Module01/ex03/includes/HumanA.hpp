/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:40:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/09 18:01:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon *weapon;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif