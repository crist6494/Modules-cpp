/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:55:17 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 19:40:35 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>
# include <string>


class Animal
{
	protected:
		std::string _name;
		std::string _type;
	public:
		Animal(std::string name);
		Animal();
		virtual ~Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		std::string getType() const;
		virtual void makeSound() const;
		
};

#endif