/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:05:28 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/16 23:36:50 by cmorales         ###   ########.fr       */
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

static std::string trim(const std::string& s)
{
    //Quitar espacios
    size_t first = s.find_first_not_of(" \t\n\r\f\v");
    size_t last = s.find_last_not_of(" \t\n\r\f\v");

    if (first == std::string::npos || last == std::string::npos)
        return s;
    return s.substr(first, last - first + 1);//Longitud cadena mas el ultimo caracter
}

bool BitcoinExchange::checkKey(const std::string& key)
{
    std::regex patron("\\d{4}-\\d{2}-\\d{2}"); // (\\d{4})cadena texto digitios(0-9) de 4 espacios \ es solo un digito
    if (!std::regex_match(key, patron))//Comprueba el patro y devuelve bool o false
        return false;
            
    this->_year = std::stoi(key.substr(0, 4));
    this->_month = std::stoi(key.substr(5, 2));
    this->_day = std::stoi(key.substr(8, 2));

    if(this->_year < 2000 || this->_year > 2023)
        return false;
    else if(this->_month < 1 || this->_month > 12)
        return false;
    else if(this->_month < 1 || this->_month > 31)
        return false;
    return true;
}

bool BitcoinExchange::checkValue(const std::string& value)
{
    try
    {
        if(std::find(value.begin(), value.end(), '.') != value.end())
        {
            size_t point_v = value.find('.');
            if(std::find((value.begin() + point_v + 1), value.end(), '.') != value.end())
                throw std::invalid_argument("Error: more than 1 decimal point.");
        }
        int has_sign = 0;
        if(value.at(0) == '+' || value.at(0) == '-')
            has_sign = 1;
        for(int i = has_sign; i < (int)value.size(); i++)
        {
            if(std::isdigit(value[i]) || value[i] == '.')
                continue;
            else
                throw std::invalid_argument("Error: not a number.");
        }
        this->_value = std::stof(value);
        if(this->_value < 0)
            throw std::invalid_argument("Error: not a positive number.");
        else if(this->_value > 1000)
            throw std::invalid_argument("Error: too large a number.");
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
        return false;
    }
    return true;
}


static bool checkInput(std::ifstream& fileInput, std::string& line, const std::string& input)
{
    if(!fileInput.is_open())
    {
        std::cerr << RED << "Error: could not open file => " << input << RESET << std::endl;
        return false;
    }
    if(fileInput.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << RED << "Error: file is empty " << RESET << std::endl;
        return false;
    }
    std::getline(fileInput, line, '\n');
    if(line != "date | value")
    {
        std::cerr << RED << "Error: invalid file format => " << line << RESET << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::findKey(const std::string& key)
{
    if(this->data.count(key) > 0)
        return true;
    return false;
}

const std::string BitcoinExchange::findClosestDate()
{
    std::cout << this->_day << std::endl;
    std::cout << this->_month << std::endl;
    std::cout << this->_year << std::endl;
    int lastDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(this->_year > 2009)
    {
        this->_day--;
        if(this->_day == 0)
            this->_month--;
        if(this->_month == 0)
        {
            this->_month = 12;
            this->_year--;
        }
        this->_day = lastDays[this->_month];
        std::string s_day = std::to_string(this->_day);
        std::string s_month = std::to_string(this->_month);
        std::string s_year = std::to_string(this->_year);
        return s_year + "-" + s_month + "-" + s_day;
    }
    return "";
}
void BitcoinExchange::printResults(std::string& key, std::string& value)
{
    while(findKey(key) == true || this->_year < 2009)
    {
        this->_year = std::stoi(key.substr(0, 4));
        this->_month = std::stoi(key.substr(5, 2));
        this->_day = std::stoi(key.substr(8, 2));
        key = findClosestDate();
    }
    std::cout << key << std::endl;
    if(findKey(key))
        std::cout << CYAN  << key << " => " << value << " = " << (this->_value * this->data[key]) << RESET << std::endl;
    else
        std::cerr << RED << "no data" << RESET << std::endl;
}


void BitcoinExchange::takeInput(const std::string& input)
{
    std::ifstream fileInput;
    std::string line;
    
    fileInput.open(input);
    if(!checkInput(fileInput, line, input))
        return;
    
    std::string key;
    std::string s_value;
    while(std::getline(fileInput, line, '\n'))
    {
        if(line.empty())
            std::cerr << RED << "Error: line is empty" << RESET << std::endl;
        key = trim(line.substr(0, line.find(" | ")));
        s_value = trim(line.substr(line.find(" | ") + 3));
        if(line.find(" | ") == std::string::npos)
            std::cerr << RED << "Error: bad input => " << key << RESET << std::endl;
        else if(!checkKey(key))
            std::cerr << RED << "Error: bad input => " << key << RESET << std::endl;
        else if(!checkValue(s_value))
            continue;
        else
            printResults(key, s_value);
    }    
    fileInput.close();
}
