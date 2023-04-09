/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:41:20 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/09 17:25:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string type);
	~Weapon();
	const std::string& getType();
	void setType(std::string type);
};

#endif 
