/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 20:41:54 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/10 11:18:50 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void mm(int x)
{
	if(x == 1)
		throw 1;
	return ;
}

int main()
{
	int x = 1;
	try{
		mm(x);
		std::cout << "Hola que tal " << std::endl;
	}
	catch(int)
	{
		std::cerr << "Error, soy tonto\n";
	}
	std::cout << "Sigue el programa";
}