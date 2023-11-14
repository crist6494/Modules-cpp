/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:08:26 by cmorales          #+#    #+#             */
/*   Updated: 2023/11/14 21:02:51 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>
# include <string>

struct Data
{
	std::string s1;
	int n;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& cpy);
		Serializer& operator=(const Serializer& src);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data*	  deserialize(uintptr_t raw);

};

#endif