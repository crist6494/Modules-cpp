/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:45:10 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 20:59:46 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */


# include <iostream>
# include <iterator>
#include <algorithm>
#include <vector>
#include <list>

class NotOccurrenceFound : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "No occurrence is found";
        }
};

template <typename T>
void easyfind(T& t, int n)
{
    typename T::iterator iter;//No confunda T::iterator con una variable pq lo suamos como tipo
    
    iter = std::find(t.begin(), t.end(), n);
    try
    {
        if(iter == t.end())
            throw NotOccurrenceFound();
        std::cout << CYAN << "Occurrence find" << std::endl << RESET;
        std::cout << MAGENTA << "Ocurrencia encontrada es: " << CYAN << *iter << std::endl << RESET;
    }
    catch(const NotOccurrenceFound& e)
    {
        std::cerr << RED << e.what() << std::endl << RESET;
    }
}

#endif