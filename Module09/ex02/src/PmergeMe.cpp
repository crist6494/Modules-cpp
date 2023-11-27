/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:08:02 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/27 20:36:57 by cmorales         ###   ########.fr       */
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
        std::cout << i << " " << vec.size() << std::endl;
        std::cout << "[";
        for (size_t j = i; j < i + currSize && j < vec.size(); j++)
        {
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

    std::vector<int>leftSide(lenLeft);
    std::vector<int>rightSide(lenRight);
    for(int i = 0; i < lenLeft; i++)
        leftSide[i] = vec[left + i];
    for(int i = 0; i < lenRight; i++)
        rightSide[i] = vec[mid + 1 + i];

    int l = 0;
    int r = 0;
    int i = left;
    while(l < lenLeft && r < lenRight)
    {
        if(leftSide[l] <= rightSide[r])
            vec.at(i) = leftSide[l++];
        else
            vec.at(i) = rightSide[r++];
        i++;
    }
    while (l < lenLeft)
        vec[i++] = leftSide[l++];

    while (r < lenRight)
        vec[i++] = rightSide[r++];
}

std::vector<int> PmergeMe::sortVector()
{
    if(isSort(this->vec) || this->vec.size() == 1)
        return this->vec;
    
    int backN = 0;
    bool odd = false;
    if(this->vec.size() % 2 != 0)
    {
        backN = vec.back();
        vec.pop_back();
        odd = true;
    }
    
    std::vector<int>s_vec;
    for (size_t i = 0; i < this->vec.size(); i ++)
        s_vec.push_back(vec.at(i));
    
    sortPair(s_vec);//sort pair [a,b]
    int len = s_vec.size();
    for(int currSize = 2; currSize < len - 1; currSize *= 2) //[a,b] [c,d]  <-++-> [a,b,c,d]
    {
        for(int left = 0; left < len - 1; left += 2 * currSize)
        {
            int mid = std::min(left + currSize - 1, len - 1);
            int right = std::min(left + 2 * currSize - 1 , len - 1);
            //std::cout << "left=" << left << " mid=" << mid << " right=" << right << std::endl;
            merge(s_vec, left, mid, right);
        }
    }
    if(odd)
    {
        std::vector<int>::iterator pos_vec = std::upper_bound(s_vec.begin(), s_vec.end(), backN);//Find correct postion
        s_vec.insert(pos_vec,backN);
    }
    return s_vec;
}

void PmergeMe::sort()
{
    this->timeInitVec = clock();
    std::cout << "Before: " << this->vec << std::endl;
    std::vector<int> s_vec = sortVector();
    this->timeEndVec = clock();//Time finish(Procesador cicles clock have to change seconds <CLOCK_PER_SEC>)
    std::cout << "Before: " << s_vec << std::endl;
    
    double r_time;
    r_time =  CLOCKS_PER_SEC * (this->timeEndVec - this->timeInitVec) / 1e6;
    std::cout << "Time to process a range of 5 elements: " << r_time << " us" << std::endl;
}
