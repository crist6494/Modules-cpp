/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:39 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/22 20:54:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

/*
void	ft_leaks(void)
{
 	system("leaks -q interface");
}*/

int main()
{
    atexit(ft_leaks);
    std::cout << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;
    
    Ice *ice = new Ice();
    src->learnMateria(ice);
    std::cout << std::endl;
    Cure *cure = new Cure();
    src->learnMateria(cure);
    
    std::cout << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout << std::endl; 
    delete tmp;
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout << std::endl;

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << std::endl;

    Character c("Cristian");
    Character f(c);

    std::cout << std::endl;

    delete ice;
    delete bob;
    delete me;
    delete src;
    delete cure;
    delete tmp;


    std::cout << std::endl;
    return 0;
}

/*
int main (void)
{

	atexit(ft_leaks);
    std::cout << std::endl;
	Character c("Pepe");
    Character d("Juan");
    Character e(d);
	IMateriaSource *me = new MateriaSource();
	Ice i1;
    Cure i2;
    Cure i3;
    Ice i4;
    Cure i5;

    std::cout << std::endl;

	me->learnMateria(&i5);
	std::cout<<std::endl;

    std::cout << std::endl;
    c.equip(&i1);
    c.equip(&i2);
    c.equip(&i3);
    
    AMateria *m = me->createMateria("cure");
	//c.equip(m);

    std::cout << std::endl;
    c.unequip(3);
    c.unequip(2);
	c.unequip(1);
	//c.unequip(0);
	c.unequip(-5);
    std::cout << std::endl;


    c.equip(&i5);
    c.use(0,e);
    std::cout << std::endl;
    
	delete me;
	delete m;
    return 0;
}*/