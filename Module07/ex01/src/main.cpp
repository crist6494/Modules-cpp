/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:52 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:01:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_string(std::string& arr)
{
    std::cout << MAGENTA << arr << ' ' << RESET;
}

int main()
{
    int i_arr[] = {1, 2, 3, 4, 5};
    std::string s_arr[4] = {"how", "are", "you", "?"};
    char c_arr[] = {'a', 'b', 'c', 'd', 'e'};
    char cc_arr[8] = "6583745";
    
    print_test(i_arr, 5, &print_arr, &sum_arr);
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    print_test(c_arr, 5, &print_arr, &sum_arr);
    std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    print_test(cc_arr, 8, &print_arr, &sum_arr);
    std::cout << std::endl << "------------------------" << std::endl;
    iter(s_arr, 5, &print_string);
    std::cout << std::endl;
}