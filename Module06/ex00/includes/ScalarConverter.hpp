/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:42:16 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/30 20:52:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */


# include <iostream>
# include <string>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& cpy);
        ScalarConverter& operator=(const ScalarConverter& src);
    public:
        static void convert(std::string s1);
};

enum{
isChar, 
isInt,
isFloat,
isDouble,
notType
};

#endif