/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:31:34 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/14 16:39:22 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie{
	
	private:
	std::string	name;
	
	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
