/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:08:02 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/27 16:57:12 by cmorales         ###   ########.fr       */
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
    *this = cpy;
    return ;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
    if(this != &src)
        this->vec = src.vec;
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
    if(s.empty() == true || (s.size() == 1 && (s.at(0) == '-' ||  s.at(0) == '+')))
        return false;
        
    size_t i = 0;
    if(s.at(0) == '+')
        i++;
    if(s.at(0) == '-')
        throw std::invalid_argument("negative number");
    for(; i < s.size(); i++)
    {
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

static bool isSort(std::vector<int> vec)
{
    for(size_t i = 0; i < vec.size() - 1; i++)
    {
        if(vec.at(i) > vec.at(i + 1))
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

PmergeMe::PmergeMe(int ac, char **av)
{
    try
    {
        for(int i = 1; i < ac; i++)
        {
            if(is_number(av[i]))
                addNumber(av[i]);
            else
                throw std::invalid_argument("no-integer find in the integer sequence");
        }
       // std::cout << this->vec << std::endl;      
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: " << e.what() << std::endl << RESET;
    }
}

void sortPair(std::vector<int>& vec)
{
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it += 2)
    {
        if ((it + 1) != vec.end() && (*it > *(it + 1)))
            std::swap(*it, *(it + 1));
    }
}

void printSubgroups(const std::vector<int>& vec, size_t currSize) {
    std::cout << "Subgrupos de tamaño " << currSize << ":" << std::endl;
    for (size_t i = 0; i < vec.size(); i += currSize)
    {
        std::cout << "[";
        for (size_t j = i; j < i + currSize && j < vec.size(); ++j) {
            std::cout << vec[j];
            if(j != i + currSize - 1)
                std::cout << ",";
        }
        std::cout << "]";
        std::cout << "   ";
    }
}

void merge(std::vector<int> &vec, int left, int mid, int right)
{
    int lenLeft = mid - left + 1;
    int lenRight = right - mid;

    //std::cout << "LENLEFT: " << lenLeft << std::endl;
    //std::cout << "RIGHTLEFT: " << lenRight << std::endl;
    std::vector<int>leftSide(lenLeft);
    std::vector<int>rightSide(lenRight);
    for(int i = 0; i < lenLeft; i++)
        leftSide[i] = vec[left + i];
    for(int i = 0; i < lenRight; i++)
        rightSide[i] = vec[mid + 1 + i];

    //std::merge(leftSide.begin(), leftSide.end(), rightSide.begin(), rightSide.end(), vec.begin() + left);
    int l = 0;
    int r = 0;
    int i = left;
    while(l < lenLeft && r < lenRight)
    {
        if(leftSide[l] <= rightSide[r])
            vec[i] = leftSide[l++];
        else
            vec[i] = rightSide[r++];
        i++;
    }
    while (l < lenLeft)
        vec[i++] = leftSide[l++];

    while (r < lenRight)
        vec[i++] = rightSide[r++];
}

void PmergeMe::sort()
{
    if(isSort(this->vec) || this->vec.size() == 1)
        return;
    
    bool odd = false;
    if(this->vec.size() % 2 != 0)
    {
        int back_n = vec.back();
        vec.pop_back();
        odd = true;
        (void)back_n;
        (void)odd;
    }
    
    std::vector<int>aux;
    for (size_t i = 0; i < this->vec.size(); i ++)
        aux.push_back(vec.at(i));
    
    sortPair(aux);//sort pair [a,b]
    int len = aux.size();
    std::cout << len << std::endl;
    for(int currSize = 2; currSize < len; currSize *= 2) //[a,b] [c,d]  <-++-> [a,b,c,d]
    {
        for(int left = 0; left < len - 1; left += 2 * currSize)
        {
            std::cout << "Left: " << left << std::endl;
            int mid = left + currSize - 1;
            int right = std::min(left + 2 * currSize - 1 , len -1);
            //std::cout << "left=" << left << " mid=" << mid << " right=" << right << std::endl;
            merge(aux, left, mid, right);
        }
        std::cout << currSize << std::endl;
    }
    std::cout << aux;
}
