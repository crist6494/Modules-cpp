/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:42:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/10 18:22:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(const std::string& name);
		Dog();
		~Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);
		void makeSound() const;
};

#endif