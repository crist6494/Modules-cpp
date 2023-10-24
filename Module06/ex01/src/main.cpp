/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:08:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/24 12:02:10 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

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
	raw = serialize(&data);
	std::cout <<"Data: " << raw << std::endl;
	std::cout <<"Int: " << data.n << std::endl;
	std::cout <<"String: " << data.s1 << std::endl;
	std::cout << "----------------\n";

	Data *dataptr;
	dataptr = deserialize(raw);
	std::cout <<"Data: " << dataptr << std::endl;
	std::cout <<"Int: " << data.n << std::endl;
	std::cout <<"String: " << data.s1 << std::endl;
}