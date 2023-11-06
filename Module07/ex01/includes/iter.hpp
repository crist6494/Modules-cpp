/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:26:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/06 12:10:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <typeinfo> 

template <typename T>
void print_arr(T& f)
{
   std::cout << f << ' ';
}

template <typename T>
void sum_arr(T& f)
{
    f += 1;
   std::cout << f << ' ';
}

template <typename T>
void iter(T *arr, int len, void (*ptrf)(T& f))
{
    for(int i = 0; i < len; i++)
    {
        ptrf(arr[i]);
    }
}

#endif