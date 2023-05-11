/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:24 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 18:31:44 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout<<"Default constructor called from Brain"<<std::endl;
}

Brain::~Brain()
{
	std::cout<<"Destructor called from Brain" <<std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout<<"Copy constructor called from Brain" <<std::endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout<<"Assignation operator called from Brain" <<std::endl;
	for(unsigned int i = 0; i < n_ideas;  i++)
	{
		this->ideas[i] = src.ideas[i];	
	}
	return *this;
}
