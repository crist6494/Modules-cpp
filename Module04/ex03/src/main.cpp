/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/21 15:51:48 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

int main (void)
{

	//atexit(check_leaks);
    
	Character c("Pepe");
    Character d("Juan");
    Character e(d);
	IMateriaSource *me = new MateriaSource();
	Ice i1;
    Cure i2;
    Cure i3;
    Ice i4;
    Cure i5;
    
	me->learnMateria(&i5);
	std::cout<<std::endl;

    c.equip(&i1);
    c.equip(&i2);
    c.equip(&i3);
    
	c.equip(me->createMateria("cure"));

    c.unequip(3);
    c.unequip(2);
	c.unequip(1);
	c.unequip(0);
	c.unequip(-3);


	c.equip(&i5);
    c.use(2,e); 

	//delete me;
    return 0;
}
