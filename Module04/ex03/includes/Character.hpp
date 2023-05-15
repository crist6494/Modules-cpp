/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:09:25 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 20:23:21 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include " ICharacter.hpp"

class Character
{
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character(std::string const &name);
  		Character();
  		~Character();
    	Character(Character const &src);

	    Character& operator=(Character const &src);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif