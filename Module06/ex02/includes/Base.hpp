/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:47:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:43:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib> //rand()
# include <ctime>//time()
# include <exception>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{   
};

class C : public Base
{   
};

Base    *generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif