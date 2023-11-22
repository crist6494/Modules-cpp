/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:08:02 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/22 14:57:18 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    return ;
}

PmergeMe::~PmergeMe()
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe& cpy)
{
    (void)cpy;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    (void)src;
    return *this;
}
std::ostream& operator<<(std::ostream& os, std::vector<int>vec)
{
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    return os;
}

static bool is_number(const std::string& s)
{
    if(s.empty() == true || (s.size() == 1 && s.at(0) == '-'))
        return false;
    size_t i = 0;
    if(s.at(0) == '+')
        i++;
    for(; i < s.size(); i++)
    {
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

void PmergeMe::addNumber(const std::string& n_input)
{
    int number;
    std::stringstream ss(n_input);
    
    ss >> number;
    this->vec.push_back(number);
    ss.str("");
}


void PmergeMe::takeInput(int ac, char **input)
{
    try
    {
        for(int i = 1; i < ac; i++)
        {
            if(is_number(input[i]))
                addNumber(input[i]);
            else
                throw std::invalid_argument("is not a number");
        }
        std::cout << this->vec << std::endl;      
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
    }
    
}



