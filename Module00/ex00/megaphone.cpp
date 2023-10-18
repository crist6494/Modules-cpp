/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:21:23 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/13 17:28:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	if(ac == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return (0);
	}
	for(int  i = 1; i < ac; i++)
	{
		for(int j = 0; av[i][j]; j++)
		{
			std::cout<<(char)(std::toupper(av[i][j]));
		}
		if(i != ac - 1)
			std::cout<<" ";
	}
	std::cout<<std::endl;
	return (0);
}
