/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:09:25 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/22 20:36:34 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <typeinfo>

typedef struct s_materias
{
	AMateria *materia;
	struct s_materias *nxt;
}t_materias;

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *_inventory[4];
		t_materias *del_list;
		
		void addElementDelete(AMateria *materia);
		void removeList(void);
		
	public:
		Character(std::string const &name);
  		Character();
  		~Character();
    	Character(const Character &src);

	    Character& operator=(const Character &src);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		void copyDeleteList(t_materias *dl);
};

#endif