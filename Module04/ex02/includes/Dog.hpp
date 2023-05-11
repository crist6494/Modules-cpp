/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:42:19 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/11 20:24:54 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_dogBrain;
	public:
		Dog();
		~Dog();
		Dog(const Dog& src);
		Dog& operator=(const Dog& src);

		void makeSound() const;
};

#endif