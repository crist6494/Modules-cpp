/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:08:02 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/29 11:58:52 by cmorales         ###   ########.fr       */
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
    {
        this->vec = src.vec;
        this->deque = src.deque;
        this->timeVec = src.timeVec;
        this->timeDeque = src.timeDeque;
    }
    return *this;
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

std::ostream& operator<<(std::ostream& os, std::vector<int>& vec)
{
    std::vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, std::deque<int>& deque)
{
    std::deque<int>::iterator it;
    for(it = deque.begin(); it != deque.end(); it++)
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

void PmergeMe::addNumber(const std::string& n_input)
{
    int number;
    std::stringstream ss(n_input);
    
    ss >> number;
    this->vec.push_back(number);
    this->deque.push_back(number);
    ss.str("");
}

PmergeMe::PmergeMe(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        if(is_number(av[i]))
            addNumber(av[i]);
        else
            throw std::invalid_argument("no-integer find in the integer sequence");
    }
}

template<typename Container>
bool isSort(Container& container)
{
    typename Container::iterator it;
    for(it = container.begin() ; it != container.end(); it++)
    {
        if(*it > *std::next(it))
            return false;
    }
    return true;
}

template<typename Container>
void merge(Container &container, int left, int mid, int right)
{
    int lenLeft = mid - left + 1;
    int lenRight = right - mid;

    Container leftSide(lenLeft);
    Container rightSide(lenRight);

    typename Container::iterator itLeft = leftSide.begin();
    typename Container::iterator itRight = rightSide.begin();
    
    for(int i = 0; i < lenLeft; i++)
    {
        *itLeft = container[left + i];
        *itLeft++;
    }
    for(int i = 0; i < lenRight; i++)
    {
        *itRight = container[mid + 1 + i];
        *itRight++;        
    }

    itLeft = leftSide.begin();
    itRight = rightSide.begin();
    int i = left;
    while(itLeft != leftSide.end() && itRight != rightSide.end())
    {
        if(*itLeft <= *itRight)
            container.at(i) = *itLeft++;
        else
            container.at(i) = *itRight++;
        i++;
    }
    while (itLeft != leftSide.end())
        container[i++] = *itLeft++;

    while (itRight != rightSide.end())
        container[i++] = *itRight++;
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
    std::copy(this->vec.begin(), this->vec.end(), std::back_inserter(s_vec));
        
    int len = s_vec.size();
    for(int currSize = 1; currSize < len; currSize *= 2) //[a,b] [c,d]  <-++-> [a,b,c,d]
    {
        for(int left = 0; left < len; left += 2 * currSize)
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

std::deque<int> PmergeMe::sortDeque()
{
    if(isSort(this->deque) || this->deque.size() == 1)
        return this->deque;
        
    int backN = 0;
    bool odd = false;
    if(this->deque.size() % 2 != 0)
    {
        backN = deque.back();
        deque.pop_back();
        odd = true;
    }
    
    std::deque<int>s_deque;
    for (size_t i = 0; i < this->deque.size(); i ++)
        s_deque.push_back(deque.at(i));
    
    int len = s_deque.size();
    for(int currSize = 1; currSize < len; currSize *= 2)
    {
        for(int left = 0; left < len; left += 2 * currSize)
        {
            int mid = std::min(left + currSize - 1, len - 1);
            int right = std::min(left + 2 * currSize - 1 , len - 1);
            merge(s_deque, left, mid, right);
        }
    }
    if(odd)
    {
        std::deque<int>::iterator pos_deque = std::upper_bound(s_deque.begin(), s_deque.end(), backN);
        s_deque.insert(pos_deque,backN);
    }
    return s_deque;
}

void PmergeMe::sort()
{
    double r_time;
    
    this->timeVec = std::clock();
    std::cout << "Before: " << this->vec << std::endl;
    std::cout << "Vector sorted: ";
    this->vec = sortVector();
    this->timeVec = std::clock() - this->timeVec; //Time finish(Procesador cicles clock have to change seconds <CLOCK_PER_SEC>)
    std::cout << this->vec << std::endl; 
    
    this->timeDeque = clock();
    std::cout << "Deque sorted:  ";
    this->deque = sortDeque();
    this->timeDeque = clock() - this->timeDeque;
    std::cout << this->deque << std::endl;
    
    r_time =  static_cast<double>(this->timeVec) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << this->vec.size() << " elements with std::vector<int> : " << r_time << " us" << std::endl;
    r_time =  static_cast<double>(this->timeDeque) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque<int>  : " << r_time << " us" << std::endl;
}
