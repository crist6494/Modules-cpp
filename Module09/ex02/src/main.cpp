/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/22 14:48:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac > 1)
    {
        PmergeMe sort;
        sort.takeInput(ac, av);
        return 0;
    }
    else
    {
        std::cerr << RED << "Error: bad arguments." << RESET << std::endl;
        std::cout << "Usage: ./PmergeMe <av>" << std::endl;
        return 1;
    }
    
}