/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:00:53 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <typeinfo> 

template <typename T>
void print_arr(T& arr)
{
   std::cout << CYAN << arr << ' ' << RESET;
}

template <typename T>
void sum_arr(T& arr)
{
    arr += 1;
    std::cout << GREEN << arr << ' ' << RESET;
}

template <typename T>
void iter(T *arr, int len, void (*f)(T& arr))
{
    for(int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}

template <typename T>
void print_test(T *arr, int len, void(*f)(T& arr), void(*j)(T& arr))
{
    std::cout << "Arr dates: ";
    iter(arr, len, f);
    std::cout << std::endl << "Sum dates: ";
    iter(arr, len, j);
}

#endif