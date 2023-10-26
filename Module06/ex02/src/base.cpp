/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:47:59 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:38:03 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
    std::cout << "Virtual desctrucotr from Base";
}

Base * generate(void)
{
    std::srand((time(0))); 
	
    int n;
    n = std::rand() % 3 + 1; //Genera numero rando lo limita 3 (+1 pa que sea de 1-3) 
    
    switch (n)
    {
    case 1:
        return new A;
        break;
    case 2:
        return new B;
        break;
    case 3:
        return new C;
        break;
    }
    std::cout << "Is not a number 1-3\n";
    return nullptr;
}

void identify(Base* p)
{
    A *a = dynamic_cast<A*>(p);
    B *b = dynamic_cast<B*>(p);
    C *c = dynamic_cast<C*>(p);

    if (a)
        std::cout << "*A" << std::endl;
    else if (b)
        std::cout << "*B" << std::endl;
    else if (c)
        std::cout << "*C" << std::endl;
    else
        std::cout << "Unknow type pointer" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "&A" << std::endl;
        (void)a;
    }
    catch(std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "&B" << std::endl;
            (void)b;
        }
        catch(std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "&C" << std::endl;
                (void)c;
            }
            catch(std::exception& e)
            {
                std::cerr << "Unknow type reference" << std::endl;
            }        
        }  
    }
}