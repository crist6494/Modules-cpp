/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/28 18:30:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <ctime>

class PmergeMe
{
    private:
        std::vector<int>vec;
        std::deque<int>deque;
        
        clock_t timeInitVec;
        clock_t timeEndVec;
        //clock_t timeInitList;
        //clock_t timeEndList;
        
        std::vector<int> sortVector();
        void addNumber(const std::string& n_input);
    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe& cpy);

        PmergeMe& operator=(const PmergeMe& src);

        std::deque<int> sortDeque();
        void sort();
};


std::ostream& operator<<(std::ostream& os, std::vector<int>& vector);
std::ostream& operator<<(std::ostream& os, std::deque<int>& deque);

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
void sortPair(Container& container)
{
    typename Container::iterator it;
    for(it = container.begin(); it != container.end(); it += 2)
    {
        if ((it + 1) != container.end() && (*it > *(it + 1)))
            std::swap(*it, *(it + 1));
    }
}
template<typename Container>
void merge(Container &container, int left, int mid, int right)
{
    std::cout << "Entra\n";
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
        {
            container.at(i) = *itLeft++;
            //*itLeft++;
        }
        else
        {
            container.at(i) = *itRight++;
            //*itRight++;
        }
        i++;
    }
    while (itLeft != leftSide.end())
    {
        container[i++] = *itLeft++;
        //itLeft++;
    }

    while (itRight != rightSide.end())
    {
        container[i++] = *itRight++;
        //itRight++;
    }
}

#endif