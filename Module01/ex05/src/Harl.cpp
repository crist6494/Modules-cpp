/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:43:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/12 20:43:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug()
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!"<<std::endl;
}

void Harl::info()
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning()
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
}

void Harl::error()
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::complain(std::string level)
{
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*array_fun[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	for(i = 0; i < 4; i++)
	{
		if(options[i].compare(level))
			break ;
	}

	if(i < 4)
		(this->*array_fun[i])();
	else
		std::cout<<"String passed do not correspond with any function!!!"<<std::endl;
}

//(this->*array_fun[i])();  * ejecuta el puntero de la funcion miembro correspondiente y necesita el this pq tiene que estar en una instancia
