/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:59 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/16 12:00:08 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include <iostream>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& cpy);
		Intern& operator=(const Intern& src);
};

#endif