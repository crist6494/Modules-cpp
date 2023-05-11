/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 11:52:28 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// void	ft_leaks (void)
// {
// 	system("leaks -q a.out");
// }

int main()
{
	std::cout << std::endl;
	const Animal* anm = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	// atexit(ft_leaks);
	std::cout << anm->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound(); //will output the cat sound!
	anm->makeSound();

	delete anm;
	delete d;
	delete c;
	
	std::cout << std::endl;
	const WrongAnimal* anmWrong = new WrongAnimal();
	const WrongAnimal* cWrong = new WrongCat();

	std::cout << anmWrong->getType() << " " << std::endl;
	std::cout << cWrong->getType() << " " << std::endl;
	anmWrong->makeSound();
	cWrong->makeSound(); //will output the animal sound!

	delete anmWrong;
	delete cWrong;
	return 0;
}
