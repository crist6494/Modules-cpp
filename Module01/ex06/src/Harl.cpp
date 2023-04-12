/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:43:15 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/13 00:46:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

void Harl::debug()
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!"<<std::endl;
	std::cout<<std::endl;
}

void Harl::info()
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
	std::cout<<std::endl;
}

void Harl::warning()
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<std::endl;
	std::cout<<std::endl;
}

void Harl::error()
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
	std::cout<<std::endl;
}

void Harl::complain(std::string level)
{
	std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int grade;
	int i;
	for(i = 0; i < 4; i++)
	{
		if(options[i].compare(level) == 0)
		{
			grade = i;
			break;
		}
	}
	
	switch(grade)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}
	
}
