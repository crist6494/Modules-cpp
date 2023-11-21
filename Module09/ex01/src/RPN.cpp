/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:05:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/21 12:14:11 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
    return ;
}

RPN::~RPN()
{
    return ;
}

RPN::RPN(const RPN& cpy)
{
    (void)cpy;
}


RPN& RPN::operator=(RPN src)
{
    (void)src;
    return *this;
}

static bool checkNum(std::string& n)
{
    int i = 0;

    if(n.size() == 1 && (n[i] == '+' || n[i] == '-'))
        return false;
    if(n[i] == '+' || n[i] == '-')
        i++;
    for(; i < (int)n.size(); i++)
    {
        if(!isdigit(n[i]))
            return false;
    }
    return true;
}

int RPN::doOperation(const std::string& s)
{
    long long res = 0;
    
    /* std::cout << "A: " << this->_a << std::endl;
    std::cout << "B: " << this->_b << std::endl; */
    if(s == "+")
        res = this->_a + this->_b;
    else if(s == "-")
        res = this->_a - this->_b;
    else if(s == "*")
        res = this->_a * this->_b;
    else if(s == "/")
    {
        if(this->_b == 0)
            throw std::invalid_argument("Division by zero");
        res = this->_a / this->_b;
    }
    return res;
}

void RPN::run(std::string input)
{
    std::string s;
    std::stringstream s_input(input);
    long long result;
    try
    {
        while(s_input >> s)
        {
            if(s.find_first_not_of("+-*/") == std::string::npos)
            {
                std::cout << queue.size() << std::endl << std::endl;;
                if(this->queue.size() < 2)
                    throw std::invalid_argument("not enough elements in the expression");
                this->_a = queue.front();
                queue.pop();
                this->_b = queue.front();
                this->queue.pop();
                result = doOperation(s);
                this->queue.push(result);
                //std::cout << a + b << std::endl; 
            }
            else if(checkNum(s))
            {
                //std::cout << "Entra: " << s << std::endl;
                this->queue.push(std::stoi(s));
            }
            else
                throw std::invalid_argument("Invalid expression");
        }
        /* if (this->queue.size() != 1) // if there is more than one element in the stack
            throw std::invalid_argument("too many operands"); */
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: "<< e.what() << std::endl << RESET;
    }
}
