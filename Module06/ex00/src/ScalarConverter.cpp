/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:44:11 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:46:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::()
{
    std::cout<<"Default constructor called from ScalarConverter"<<std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout<<"Destructor called from ScalarConverter"<<std::endl;
}

ScalarConverter::(const ScalarConverter& cpy)
{
    std::cout<<"Constructor copy called from ScalarConverter"<<std::endl;
    
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
    std::cout<<"Assignation operator called from ScalarConverter"<<std::endl;
    if(this == &src)
        return *this;
    return *this;
}
