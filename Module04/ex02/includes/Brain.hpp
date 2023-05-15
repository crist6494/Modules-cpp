/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:18:22 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/15 19:06:38 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
	private:
		static const unsigned int n_ideas = 100; 
	public:
		std::string ideas[n_ideas];
		
		Brain();
		~Brain();
		Brain(const Brain& src);
		
		Brain& operator=(const Brain& src);
};

#endif