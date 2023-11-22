/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:37:48 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/22 13:02:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <regex>

class BitcoinExchange
{
    private:
        std::map<std::string, float> data;
        int _day;
        int _month;
        int _year;
        float _value;
        bool checkKey(const std::string& key);
        bool checkValue(const std::string& value);
        bool findKey(const std::string& key);
        const std::string findClosestDate(std::string& key);
        void printResults(std::string& key, std::string& value);
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);

        BitcoinExchange& operator=(const BitcoinExchange& src);

        void takeData(const std::string& filename);
        void takeInput(const std::string& input);

        std::map<std::string, float> getData();
};

std::ostream& operator<<(std::ostream& os, BitcoinExchange& btc);

#endif