/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:38:06 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/15 17:14:27 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define BLUE			"\033[34m"				/* Blue */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

# include <iostream>
# include <stack>
# include <list>
# include <exception>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& cpy);

        MutantStack& operator=(const MutantStack& src);

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
};

template<typename T>
MutantStack<T>::MutantStack()
{
	std::cout<<"Default constructor called from MutanStack"<<std::endl;
}
template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED <<"Destructor called from MutanStack"<<std::endl << RESET;
}
template<typename T>
MutantStack<T>::MutantStack(const MutantStack& cpy)
{
	std::cout << YELLOW <<"Copy constructor called from MutanStack"<<std::endl << RESET;
    *this = cpy;
}
template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src)
{
	std::cout << YELLOW <<"Assignation operator called from MutanStack"<<std::endl << RESET;
    if(this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()//Pa decirle que it es una variable y no uan declaracion de funcion
{
    return std::stack<T>::c.begin();//Para acceder a la variable c que tiene el contenedor subyacente
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

#endif