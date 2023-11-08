/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:11:12 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/08 11:44:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    std::cout<<"Default constructor called from Span"<<std::endl;
}
Span::Span(unsigned int N)
    :_n(N)
{
    std::cout << GREEN <<"Constructor with parameters called from Span with N: " << this->getN() <<std::endl << RESET;
}
Span::~Span()
{
    std::cout << RED <<"Destructor constructor called from Span whit N: " << this->getN() <<std::endl << RESET;
}
Span::Span(const Span& cpy)
{
    std::cout << YELLOW <<"Copy Constructor called from Span"<<std::endl << RESET;
    *this = cpy; 
}
        
Span& Span::operator=(const Span& src)
{
    std::cout << YELLOW << "Assignment operator called from Span"<<std::endl << RESET;
    if(this != &src)
        this->_n = src._n;
    return *this;
}

unsigned int Span::getN()
{
    return this->_n;
}