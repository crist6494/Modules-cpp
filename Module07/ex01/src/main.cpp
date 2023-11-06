/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:52 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/06 12:06:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print_test(T *arr, int len, void(*ptrf)(T& f))
{
    std::cout << "Arr type: " << typeid(*arr).name() << std::endl;
    std::cout << "Arr dates: ";
    iter(arr, len, ptrf);
}

int main()
{
    int i_arr[] = {1, 2, 3, 4, 5};
    
    char c_arr[] = {'a', 'b', 'c', 'd', 'e'};
    
    print_test(i_arr, 5, &print_arr);
    std::cout << std::endl;
    print_test(c_arr, 5, &print_arr);
}