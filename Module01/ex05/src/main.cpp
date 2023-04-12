/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:22:17 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/12 20:36:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout<<"DEBUG: "<<std::endl;
	harl.complain("DEBUG");
	std::cout<<std::endl;
	std::cout<<"INFO: "<<std::endl;
	harl.complain("INFO");
	std::cout<<std::endl;
	std::cout<<"WARNING: "<<std::endl;
	harl.complain("WARNING");	
	std::cout<<std::endl;
	std::cout<<"ERROR: "<<std::endl;
	harl.complain("ERROR");
	return 0;
}