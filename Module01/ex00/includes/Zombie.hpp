/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:48:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/12 18:47:46 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie{
	
	private:
	std::string	name;
	
	public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif