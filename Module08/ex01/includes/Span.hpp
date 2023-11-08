/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:10:00 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/08 11:55:32 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <vector>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& cpy);
        
        Span& operator=(const Span& src);

        unsigned int getN();
        void addNumber(int number);
};

#endif