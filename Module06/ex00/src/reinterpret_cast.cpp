/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinterpret_cast.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:48:26 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/19 20:40:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* int main()
{
	std::cout << "Tamaño char:   " << sizeof(char) <<std::endl;
	std::cout << "Tamaño char*:  " << sizeof(char*) <<std::endl;
	std::cout << "Tamaño int:    " << sizeof(int) <<std::endl;
	std::cout << "Tamaño int*:   " << sizeof(int*) <<std::endl;
	std::cout << "Tamaño long:   " << sizeof(long) <<std::endl;
	std::cout << "Tamaño float:  " << sizeof(float) <<std::endl;
	std::cout << "Tamaño double: " << sizeof(double) <<std::endl;
	std::cout << "-----------------" << std::endl;

	int o = 65;
	int* n = &o;
	
	int &d = reinterpret_cast<int &>(n);
	std::cout << d<< std::endl;
	std::cout << "-----------------" << std::endl;
	
	char* c = reinterpret_cast<char*>(n);
	std::cout << *n << std::endl;
	std::cout << *c << std::endl;
	*n += 1;
	std::cout << *n << std::endl;
	std::cout << *c << std::endl;
} */