/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:36:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* void	ft_leaks (void)
{
 	system("leaks -q abstract");
} */

int main()
{
	//atexit(ft_leaks);
	std::cout << std::endl;
    AAnimal *a = new Dog();
    AAnimal *b = new Cat();

	a->getType();
	b->getType();

	std::cout << std::endl;
    
    a->makeSound();
    b->makeSound();

	std::cout << std::endl;

    delete a;
    delete b;
	std::cout << std::endl;

    return 0;
}

