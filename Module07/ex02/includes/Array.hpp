/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:19:25 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/06 21:13:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <string>

template <typename T>
class Array
{
    private:
        unsigned int _n;
    public:
        T *_arr;
        Array()
            :_n(0),_arr(nullptr)
        {
	        std::cout<<"Default constructor called from Array"<<std::endl;
        }
        Array(unsigned int n)
            :_n(n), _arr(new T[_n])
        {
	        std::cout << GREEN <<"Constructor with parameters called from Array of: " << _n << " elements" <<std::endl << RESET;
        }
        ~Array()
        {
	        std::cout << RED <<"Destructor called from Array"<<std::endl << RESET;
            delete[] _arr;
            this->_arr = nullptr;
        }
        Array(const Array& cpy)
        {
	        std::cout << YELLOW <<"Destructor called from Array"<<std::endl << RESET;
            *this = cpy;
        }
        Array& operator=(const Array& src)
        {
	        std::cout << YELLOW <<"Assignation operator called from Array"<<std::endl << RESET;
            if(this != &src)
            {
                delete[] this->_arr;
                this->_n = src._n
                this->_arr = new T[_n];
                for(int i = 0; i < 4; i++)
                    *(this->_arr[i]) = *(src._arr[i]);
            }
            return *this;
        }
        unsigned int getN()
        {
            return this->_n;
        }
        
};

template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& arr)
{
    for(unsigned int i = 0; i < arr.getN(); i++)
        os << CYAN << arr._arr[i] << ' ';
    os << std::endl;
    return os;
}

#endif