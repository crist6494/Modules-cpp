/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:24:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/20 21:17:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char **av)
{
    if(ac == 2)
    {
        BitcoinExchange btc;
        btc.takeData("data.csv");
        btc.takeInput(av[1]);
        return 0;
    }
    std::cout << RED << "Error: could not open file." << RESET << std::endl;
    return 1;
}