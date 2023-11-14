/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:35:46 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:00:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::cout << std::endl << "----------Vector----------" << std::endl;
    std::vector<int> vec;

    for(int i = 1; i <  8; i++)
        vec.push_back(i * 3);
        
    std::cout << MAGENTA << "Elementos del vector: " << RESET;
    for(size_t j = 0; j < vec.size(); j++)
        std::cout << CYAN << vec[j] << ' ' << RESET;
    std::cout << std::endl;
    
    int n = 3;
    easyfind(vec, n);
    
    std::cout << std::endl << "----------List------------" << std::endl;
    std::list<int> list;

    std::cout << MAGENTA << "Elementos de la lista: " << RESET;
	for (int i = 0; i <= 20; i++) {
		list.push_back(i);
        std::cout << CYAN << i << ' ' << RESET;
	}
    std::cout << std::endl;
    std::list<int>::const_iterator iter_list;
	easyfind(list, 2);
	easyfind(list, 19);
	easyfind(list, 50);
}
