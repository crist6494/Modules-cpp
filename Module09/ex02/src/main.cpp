/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:04 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/28 20:46:15 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac > 1)
    {
        try
        {
            PmergeMe sortMerge(ac, av);
            sortMerge.sort();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
        }
            return 0;
        }
    else
    {
        std::cerr << RED << "Error: bad arguments." << RESET << std::endl;
        std::cout << "Usage: ./PmergeMe <av>" << std::endl;
        return 1;
    }
    
}