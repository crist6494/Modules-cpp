/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:44:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/30 16:20:30 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout<<"Default constructor called from ScalarConverter"<<std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout<<"Destructor called from ScalarConverter"<<std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    std::cout<<"Constructor copy called from ScalarConverter"<<std::endl;
    (void)cpy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    std::cout<<"Assignation operator called from ScalarConverter"<<std::endl;
    if(this == &src)
        return *this;
    return *this;
}


static int is_char(std::string s1)
{
    if(s1.length() == 1 && std::isprint((s1[0])) && !std::isdigit((s1[0])))
        return 1;
    return 0;
}

static void cast_char(std::string s1)
{
   
    char toChar = s1[0];
    std::cout << CYAN << "char: " << toChar << std::endl;
    std::cout << CYAN << "int: " << static_cast<int>(toChar) << std::endl;
    std::cout << CYAN << "float: " << static_cast<float>(toChar) << ".0f" << std::endl;
    std::cout << CYAN << "double: " << static_cast<double>(toChar) << ".0" << std::endl <<RESET;
}
static int getType(std::string s1)
{
    if(is_char(s1))
        return isChar;
    return notType;
}


void ScalarConverter::convert(std::string s1)
{
    int type;

    type = getType((s1));
    switch ((type))
    {
    case 1: cast_char(s1);
        break;
    default: std::cout << RED << "Not type found" << RESET << std::endl;
        break;
    }
}