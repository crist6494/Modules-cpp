/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:31:34 by cmorales          #+#    #+#             */
/*   Updated: 2023/03/30 19:45:16 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie{
	
	private:
	std::string	name;
	
	public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif
