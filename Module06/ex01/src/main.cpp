/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:08:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:03:12 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

	data.n = 42;
	data.s1 = "Cristian";

	std::cout <<"Data: " << &data << std::endl;
	std::cout <<"Int: " << data.n << std::endl;
	std::cout <<"String: " << data.s1 << std::endl;
	std::cout << "----------------\n";
	
	uintptr_t raw;
	raw = Serializer::serialize(&data);
	std::cout <<"Data: " << raw << std::endl;
	std::cout << "----------------\n";

	Data *dataptr;
	dataptr = Serializer::deserialize(raw);
	std::cout <<"Data: " << dataptr << std::endl;
	std::cout <<"Int: " << dataptr->n << std::endl;
	std::cout <<"String: " << dataptr->s1 << std::endl;
}