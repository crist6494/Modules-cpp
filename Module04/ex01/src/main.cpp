/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:52:30 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:14:28 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/*void	ft_leaks (void)
{
 	system("leaks -q brain");
}*/

int main()
{
	std::cout << std::endl;
	const unsigned int n_animals = 6;
	Animal *animals[n_animals];

	//atexit(ft_leaks);

	for(unsigned int i = 0; i < n_animals; i++)
    {
        if(i % 2 == 0)
		{
            animals[i] = new Dog();
			std::cout << std::endl;
		}
        else
		{
            animals[i] = new Cat();
			std::cout << std::endl;
		}
    }

    for(unsigned int i = 0; i < n_animals; i++)
    {
        delete animals[i];
		std::cout << std::endl;
    }
	
	return 0;
}
