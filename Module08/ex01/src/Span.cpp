/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:17:45 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/15 20:47:57 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
    :_size(0),_lim(0), _vec(0)
{
    std::cout<<"Default constructor called from Span"<<std::endl;
}
Span::Span(unsigned int N)
    :_size(0),_lim(N), _vec(0)
{
    std::cout << GREEN <<"Constructor with parameters called from Span with N: " << this->getLim() <<std::endl << RESET;
}
Span::~Span()
{
    std::cout << RED <<"Destructor constructor called from Span whit N: " << this->getLim() <<std::endl << RESET;
}
Span::Span(const Span& cpy)
    :_size(cpy._size), _lim(cpy._lim), _vec(cpy._vec)
{
    std::cout << YELLOW <<"Copy Constructor called from Span"<<std::endl << RESET;
}        
Span& Span::operator=(const Span& src)
{
    std::cout << YELLOW << "Assignment operator called from Span"<<std::endl << RESET;
    if(this != &src)
    {
        this->_vec = src._vec;
        this->_size = src._size;
        this->_lim = src._lim;
    }
    return *this;
}

unsigned int Span::getLim()
{
    return this->_lim;
}

unsigned int Span::getSize()
{
    return this->_size;
}

std::vector<int> Span::getVec()
{
    return this->_vec;
}

const char* Span::OverflowStore::what() const throw()
{
    return "Overflow the store container";
}

const char* Span::NotFoundNum::what() const throw()
{
    return "Not found the num";
}

void Span::addNumber(int num)
{
    if((this->_lim - 1) < this->_size)
        throw Span::OverflowStore();
    this->_vec.push_back(num);
    this->_size++;
    std::cout << "Integer added correctly: " << num << std::endl;
}

unsigned int Span::shortestSpan()
{
   if(this->_lim <= 1)
        throw std::length_error("Not enough number");
    std::vector<int> store(this->_vec.size());
    std::adjacent_difference(this->_vec.begin(), this->_vec.end(), store.begin());
    //calcula la distacia entre el de al lado ->{3,63,1,2} -> 63-3, 1-63, 2-1 = 60,-62,1
    std::vector<int>::iterator it = store.begin();
    for (it = store.begin(); it != store.end(); ++it) {
        *it = std::abs(*it);
    }
    std::vector<int>::iterator min= std::min_element(store.begin() + 1, store.end());
    std::cout << YELLOW << "Longest integer: " << *min << RESET << std::endl;
    return *min;
}

unsigned int Span::longestSpan()
{
    if(this->_lim <= 1)
        throw std::length_error("Not enough number");
    std::vector<int> store(this->_vec.size());
    std::adjacent_difference(this->_vec.begin(), this->_vec.end(), store.begin());

    std::vector<int>::iterator it = store.begin();
    for (it = store.begin(); it != store.end(); ++it) {
        *it = std::abs(*it);
    }
    std::vector<int>::iterator max= std::max_element(store.begin() + 1, store.end());
    std::cout << YELLOW << "Longest integer: " << *max << RESET << std::endl;
    return *max;
}

void Span::fillSpanNumber()
{
    std::cout << "fillSpanNumber function called" << std::endl;
    srand(time(NULL));
    for(unsigned int i = 0; i < this->_lim; i++)
    {
        if((this->_lim -1) < this->_size)
            throw NotFoundNum();
        std::back_inserter(this->_vec) = rand() % 80;
        this->_size++;
    }
}

std::ostream& operator<<(std::ostream& os, Span& src)
{
    std::vector<int> v = src.getVec();
    std::cout << MAGENTA << "Vector elements: " << CYAN;
    if(v.size())
    {
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl << RESET;
    }
    else if(v.size() == 0)
    {
        for(unsigned int i = 0; i < src.getLim(); i++)
            std::cout << CYAN << '0' << ' ' << RESET;
        std::cout << std::endl;
    }
    return os;   
}
