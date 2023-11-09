/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:19:25 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/09 20:56:52 by cmorales         ###   ########.fr       */
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
        unsigned int _size;
        T *_arr;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& cpy);
        
        Array& operator=(const Array& src);

        T& operator[](unsigned int n);

        unsigned int size() const;
        T* getArr() const;
};

template <typename T>
Array<T>::Array()
    :_size(0),_arr(new T[0])
{
	std::cout<<"Default constructor called from Array"<<std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
    :_size(n), _arr(new T[_size])
{
	std::cout << GREEN <<"Constructor with parameters called from Array of: " << _size << " elements" <<std::endl << RESET;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << RED <<"Destructor called from Array"<<std::endl << RESET;
    delete[] _arr;
    this->_arr = nullptr;
}

template <typename T>
Array<T>::Array(const Array<T>& cpy)
    :_size(cpy._size), _arr(new T[_size])
{
	std::cout << YELLOW <<"Copy constructor called from Array"<<std::endl << RESET;
    for(unsigned int i = 0; i < this->size(); i++)
            this->_arr[i] = cpy._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src)
{
	std::cout << YELLOW <<"Assignation operator called from Array"<<std::endl << RESET;
    if(this != &src)
    {
        delete[] this->_arr;
        this->_size = src._size;
        this->_arr = new T[_size];
        for(unsigned int i = 0; i < src.size(); i++)
            this->_arr[i] = src._arr[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n)
{
    if(n >= 0 && n < this->_size)
        return this->_arr[n];
    else
        throw std::out_of_range("Index out of bounds");
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}

template <typename T>
T* Array<T>::getArr() const
{
    return this->_arr;
}

        
template <typename T>
std::ostream& operator<<(std::ostream& os, Array<T>& arr)
{
    std::cout << MAGENTA << "Array de " << arr.size() << " elemntos que contiene: ";
    for(unsigned int i = 0; i < arr.size(); i++)
        os << CYAN << arr.getArr()[i] << ' ';
    os << RESET;
    return os;
}

#endif