/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:10:00 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 20:59:26 by cmorales         ###   ########.fr       */
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
# include <exception>
# include <cstdlib>
# include <ctime> 

class Span
{
    private:
        unsigned int _size;
        unsigned int _lim;
        std::vector<int> _vec;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span& cpy);
        
        Span& operator=(const Span& src);

        std::vector<int> getVec();
        unsigned int getLim();
        unsigned int getSize();
        
        void addNumber(int num);
        
        class OverflowStore : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        unsigned int shortestSpan();
        unsigned int longestSpan();

         class NotFoundNum : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        void fillSpanNumber();
};

std::ostream& operator<<(std::ostream& os, Span& src);

#endif