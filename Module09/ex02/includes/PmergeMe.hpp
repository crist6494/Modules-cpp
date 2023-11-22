/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:06:29 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/22 14:47:20 by cmorales         ###   ########.fr       */
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
# include <sstream>

class PmergeMe
{
    private:
        std::vector<int>vec;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& cpy);

        PmergeMe& operator=(const PmergeMe& src);

        void takeInput(int ac, char **input);
        void addNumber(const std::string& n_input);
};

std::ostream& operator<<(std::ostream& os, std::vector<int>);

#endif