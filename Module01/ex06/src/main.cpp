/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:22:17 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/13 00:45:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if(ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Usage: ./harl_filter \"level\"\n";
	return 0;
}