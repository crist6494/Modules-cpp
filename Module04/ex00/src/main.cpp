/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 11:51:42 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal a;
	Cat b;
	Dog c;

	//a.makesound();
	//b.makesound();
	//c.makesound();
	//Static binding

	//dir = &b;
	//dir->makesound();
	//dir = &c;
	//c.sound();
	Animal *dir[] = {&a, &b, &c};

	for(int i = 0; i < 3; i++){
		dir[i]->makesound();
	}
}