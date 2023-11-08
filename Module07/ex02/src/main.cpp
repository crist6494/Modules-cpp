/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:11:22 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/07 23:32:52 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> arr(4);
    Array<int> arr2(arr);

    for(int i = 0; i < 4; i++)
    {
        arr[i] = i + 1;
        arr2[i] = (i + 1) * 2;
    }
    std::cout << std::endl;
    std::cout << arr<< std::endl;
    std::cout << arr2 << std::endl;
    std::cout << std::endl;
    std::cout << MAGENTA << "Elemento 2 del array es: " << CYAN << arr[2] << std::endl << RESET;
    std::cout << MAGENTA << "Elemento 3 del array es: " << CYAN << arr2[3] << std::endl << RESET;
    std::cout << std::endl;
    try
    {
        std::cout << arr[-1] << std::endl;
        std::cout << arr2[3] << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << RED << "--Exception--> "<< e.what() << std::endl << RESET;
    }
    
}