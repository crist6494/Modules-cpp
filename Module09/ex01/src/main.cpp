/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:47:48 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/21 00:07:45 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {
        RPN rpn;
        rpn.run(av[1]);
    }
    else
    {
        std::cerr << RED << "Error bad arguments." << RESET << std::endl;
        std::cout << "Usage: ./RPN ""\"<expression>\"" << std::endl;
    }
}