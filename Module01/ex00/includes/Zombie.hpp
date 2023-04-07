/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:48:44 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/30 18:55:33 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

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