/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:44:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/05 23:31:44 by cmorales         ###   ########.fr       */
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

static bool is_char(std::string s)
{
    if(s.length() == 1 && isprint(s[0]) && !isnumber((s[0])))
        return true;
    return false;
}

static bool is_int(std::string s)
{
    int i = 0;
    if(s[i] == '+' || s[i] == '-' || std::isdigit(s[0]))
        i++;
    for(int j = i; j < (int)s.length(); j++)
    {
        if(!std::isdigit(s[j]))
            return false;
    }
    return true;
}

static bool is_float(std::string s)
{
    int i = 0;
    int p = 0;
    
    int len = s.size();
    if(s[len - 1] != 'f')
        return false;
    if(s[i] == '+' || s[i] == '-' || std::isdigit(s[0]))
        i++;
    for(int j = i; j < len; j++)
    {
        if(s[j] == '.' && s[j + 1] == '0')
        {
            p++;
            continue;
        }
        if(s[j] == 'f')
            continue;
        else if(!std::isdigit(s[j]))
            return false;
    }
    if(p == 0)
        return false;
    return true;
}

static bool is_double(std::string s)
{
    int i = 0;
    int p = 0;
    
    int len = s.size();
    if(s[len - 1] == 'f')
        return false;
    if(s[i] == '+' || s[i] == '-' || std::isdigit(s[0]))
        i++;
    for(int j = i; j < len; j++)
    {
        if(s[j] == '.' && s[j + 1] == '0')
        {
            p++;
            continue;
        }
        if(!std::isdigit(s[j]))
            return false;
    }
    if(p == 0)
        return false;
    return true;
}

static int is_pseudo(std::string s)
{
    if(s == "inff" || s == "-inff" || s == "nanf")
        return 1;
    if(s == "inf" || s == "-inf" || s == "nan")
        return 2;
    return -1;
}


static void castChar(std::string s)
{
    char _c = s[0];
    
    std::cout << CYAN << "char:   " << _c << std::endl;
    std::cout << GREEN << "int:    " << static_cast<int>(_c) << std::endl;
    std::cout << YELLOW << "float:  " << static_cast<float>(_c) << ".0f" << std::endl;
    std::cout << MAGENTA << "double: " << static_cast<double>(_c) << ".0" << std::endl << RESET;
}

static void castInt(std::string s)
{
    int _i = std::stoi(s);
    
    if(_i < 32 || _i > 126)
            std::cout << CYAN << "char:   not displayable" << std::endl;
    else
        std::cout << CYAN << "char:   " << static_cast<char>(_i)<< std::endl;    
        std::cout << GREEN << "int:    " << _i << std::endl;
        std::cout << YELLOW << "float:  " << static_cast<float>(_i) << ".0f" << std::endl;
        std::cout << MAGENTA << "double: " << static_cast<double>(_i) << ".0" << std::endl << RESET;
}

static void castFloat(std::string s)
{
    float _f = std::stof(s);
    
        if(_f < 32 || _f > 126)
        std::cout << CYAN << "char:   not displayable" << std::endl;
    else
        std::cout << CYAN << "char:   " << static_cast<char>(_f)<< std::endl;
        
    std::cout << GREEN << "int:    " << static_cast<int>(_f) << std::endl;
    std::cout << YELLOW << "float:  " << _f << ".0f" << std::endl;
    std::cout << MAGENTA << "double: " << static_cast<double>(_f) << ".0" << std::endl << RESET;
}

static void castDouble(std::string s)
{
    double _d = std::stod(s);
    
    if(_d < 32 || _d > 126)
        std::cout << CYAN << "char:   not displayable" << std::endl;
    else
        std::cout << CYAN << "char:   " << static_cast<char>(_d)<< std::endl;
        
    std::cout << GREEN << "int:    " << static_cast<int>(_d) << std::endl;
    std::cout << YELLOW << "float:  " << static_cast<float>(_d) << ".0f" << std::endl;
    std::cout << MAGENTA << "double: " << _d << ".0" << std::endl << RESET;
}

static void castPseudoFloat(std::string s)
{
    std::string notf = s.substr(0, s.size() - 1);
    
    std::cout << CYAN << "char:   impossible" << std::endl; 
    std::cout << GREEN << "int:    impossible   " << std::endl;
    std::cout << YELLOW << "float:  " << s << std::endl;
    std::cout << MAGENTA << "double: " << notf << std::endl << RESET;
}

static void castPseudoDouble(std::string s)
{
    std::cout << CYAN << "char:   impossible" << std::endl; 
    std::cout << GREEN << "int:    impossible   " << std::endl;
    std::cout << YELLOW << "float:  " << s << "f" << std::endl;
    std::cout << MAGENTA << "double: " << s  << std::endl << RESET;
}


static int getType(std::string s)
{
    if(is_char(s))
        return isChar;
    else if(is_int(s))
        return isInt;
    else if(is_float(s))
        return isFloat;
    else if(is_double(s))
        return isDouble;
    else if(is_pseudo(s) == 1)
        return isPseudoFloat;
    else if(is_pseudo(s) == 2)
        return isPseudoDouble;
    return notType;
}


void ScalarConverter::convert(std::string s)
{
    int type;

    type = getType((s));
    switch ((type))
    {
    case isChar: castChar(s);
        break;
    case isInt: castInt(s);
        break;
    case isFloat: castFloat(s);
        break;
    case isDouble: castDouble(s);
        break;
    case isPseudoFloat: castPseudoFloat(s);
        break;
    case isPseudoDouble: castPseudoDouble(s);
        break;
    default:
        throw std::exception();
        break;
    }
}
