/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:06:07 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 20:59:07 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    int n;
    std::cout << "Enter the maximum capacity of the vector: ";
    std::cin >> n;
    try
    {
        if(n < 0)
            throw std::exception();
        Span s(static_cast<unsigned int>(n));
        std::cout << s;
        s.fillSpanNumber();
        std::cout << s;
        s.shortestSpan();
        s.longestSpan();
    }
    catch(const Span::OverflowStore& e)
    {
        std::cerr << RED << "Exception: " << e.what() << std::endl << RESET;
    }
    catch(const Span::NotFoundNum& e)
    {
        std::cerr << RED << "Exception: " << e.what() << std::endl << RESET;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << " Exception: Ivalid negative number as argument" << std::endl << RESET;
    }

    std::cout << std::endl  << BLUE << "-------------OTHER TEST WITHOUT DINAMIC VALOR-----------------" << RESET <<std::endl;
    try
    {
        Span s(5);
        std::cout << s;
        s.addNumber(65);
        s.addNumber(6);
        s.addNumber(28);
        s.addNumber(23);
        s.addNumber(54);
        std::cout << s;
        s.shortestSpan();
        s.longestSpan();
    }
    catch(const Span::OverflowStore& e)
    {
        std::cerr << RED << "Exception: " << e.what() << std::endl << RESET;
    }
    catch(const Span::NotFoundNum& e)
    {
        std::cerr << RED << "Exception: " << e.what() << std::endl << RESET;
    }
}

/* int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
return 0;
} */