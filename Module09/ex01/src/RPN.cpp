/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:05:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/23 11:50:17 by cmorales         ###   ########.fr       */
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
    *this = cpy;
}


RPN& RPN::operator=(RPN src)
{
    if(this != &src)
        this->stack = src.stack;
    return *this;
}

static int 
stoi(const std::string& s)
{
    std::stringstream convert(s);
    int number;
    convert >> number;
    return number;
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
    
    if(s == "+")
        res = this->_a + this->_b;
    else if(s == "-")
        res = this->_a - this->_b;
    else if(s == "*")
        res = this->_a * this->_b;
    else if(s == "/")
    {
        if(this->_a == 0)
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
                if(this->stack.size() < 2)
                    throw std::invalid_argument("not enough elements in the expression");
                this->_b = stack.top(); //First b -> LIFO (3 2) b = 2; a = 3
                stack.pop();
                this->_a = stack.top();
                this->stack.pop();
                result = doOperation(s);
                this->stack.push(result);
            }
            else if(checkNum(s))
                this->stack.push(::stoi(s));
            else
                throw std::invalid_argument("Invalid expression");
        }
        if(this->stack.size() != 1) // if there is more than one element in the stack
            throw std::invalid_argument("too many operands");
        std::cout << std::endl << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << "Error: "<< e.what() << std::endl << RESET;
    }
}
