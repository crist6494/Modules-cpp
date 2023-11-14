/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:36:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 20:58:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << BLUE << "------------STACK------------" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    
    std::cout << BLUE << "------------LIST------------" << RESET << std::endl;
    
    std::list<int> listack;
    listack.push_back(5);
    listack.push_back(17);
    std::cout << listack.back() << std::endl;
    listack.pop_back();
    std::cout << listack.size() << std::endl;
    listack.push_back(3);
    listack.push_back(5);
    listack.push_back(737);
    //[...]
    listack.push_back(0);
    std::list<int>::iterator lit = listack.begin();
    std::list<int>::iterator lite = listack.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    return 0;
}


/* int main()
{
    MutantStack<int> mstack;
    mstack.push_back(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Stack: ";
    std::copy(it, ite, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Comienzo: " << *it << std::endl;
    it += 3;
    std::cout << "Comienzo: " << *it << std::endl;
    std::cout << "Final: " << *ite << std::endl;
} */