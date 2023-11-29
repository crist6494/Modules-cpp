/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/29 00:18:00 by cmorales         ###   ########.fr       */
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
# include <chrono>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int>vec;
        std::deque<int>deque;

        clock_t timeVec;
        clock_t timeDeque;
        
        void addNumber(const std::string& n_input);
        
        std::vector<int> sortVector();
        std::deque<int> sortDeque();
        
    public:
        PmergeMe();
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe& cpy);

        PmergeMe& operator=(const PmergeMe& src);

        void sort();
};

std::ostream& operator<<(std::ostream& os, std::vector<int>& vector);
std::ostream& operator<<(std::ostream& os, std::deque<int>& deque);


/* template<typename Container>
void sortPair(Container& container)
{
    typename Container::iterator it;
    for(it = container.begin(); it != container.end(); it += 2)
    {
        if ((it + 1) != container.end() && (*it > *(it + 1)))
            std::swap(*it, *(it + 1));
    }
} */

#endif