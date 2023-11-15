/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:05:28 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/15 12:21:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    return ;
}

BitcoinExchange::~BitcoinExchange()
{
    return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
    (void)cpy;
    return;
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    if(this != &src)
        (void)src;
    (void)src;
    return *this;
}

void BitcoinExchange::takeData(const std::string& filename)
{
    std::ifstream fileData;

    fileData.open(filename);
    if(!fileData.is_open())
    {
        std::cout << RED << "Error: could not open file -> " << filename << RESET << std::endl;
        return ;
    }
    
    std::string line;
    std::string key;
    float value;
    
    std::getline(fileData, line, '\n');
    while(std::getline(fileData, line, '\n'))
    {
        key = line.substr(0, line.find(','));
        try
        {
            std::string stringFloat = line.substr(line.find(',') + 1);
            value = std::stof(stringFloat);
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
        }
        this->data.insert(std::make_pair(key, value));
    }
    fileData.close();
/*     std::cout << CYAN << "Empieza aqui: " << RESET << std::endl;
    for(std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++)
        std::cout << it->first << ": " << std::fixed << std::setprecision(2) << it->second << " " << std::endl; */
}

void BitcoinExchange::takeInput(const std::string& input)
{
    std::ifstream fileInput;

    fileInput.open(input);
    if(!fileInput.is_open())
    {
        std::cout << RED << "Error: could not open file -> " << input << RESET << std::endl;
        return ;
    }
    std::string line;
    std::string key;

    std::getline(fileInput, line, '\n');
    while(std::getline(fileInput, line, '\n'))
    {
        if(line.empty())
            continue;
        //key = trim(line.substr(0, line.find(' ')));
        if(line.find('|') == std::string::npos)
        {
            std::cerr << RED << "Error: bad input => " << key << RESET << std::endl;
            continue;
        }
        std::cout << key << std::endl;
        //std::cout << line << std::endl;
    }    
    fileInput.close();
}

/* std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r"); // Busca el primer carácter que no es un espacio en blanco
    size_t last = str.find_last_not_of(" \t\n\r");  // Busca el último carácter que no es un espacio en blanco

    if (first == std::string::npos) // La cadena está compuesta solo de espacios en blanco
        return "";

    return str.substr(first, (last - first + 1));
} */


