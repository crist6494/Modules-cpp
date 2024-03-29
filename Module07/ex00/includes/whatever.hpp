/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:05:37 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:00:26 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */


# include <iostream>
# include <string>

template <typename T>
void swap(T &a, T &b)
{
    T aux;
    
    aux = a;
    a = b;
    b = aux;
}
template <typename T>
T min(T a, T b)
{
    if( a == b)
        return b;
    else if(a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T a, T b)
{
    if( a == b)
        return b;
    else if(a > b)
        return a;
    else
        return b;
}

template <typename T>
void print_results(T a, T b)
{
    std::cout << GREEN << "Valor de a: " << a << " Valor de b: " << b << std::endl << RESET;
    swap(a, b);
    std::cout << CYAN << "Swap(a, b) -> " << "Valor de a: " << a << " Valor de b: " << b << std::endl << RESET;
    std::cout << "Valor minimo es: " << min(a, b) << std::endl << RESET;
    std::cout << "Valor maximo es: " << max(a, b) << std::endl << RESET;
    std::cout << "----------------------"<< std::endl << RESET;
    std::cout << std::endl;
}

#endif