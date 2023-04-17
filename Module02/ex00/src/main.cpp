/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:46:55 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/17 20:36:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	a.print_class();
	Fixed b(a);
	b.print_class();
	Fixed c;
	c = b;
	c.print_class();
	//std::cout << a.getRawBits() << std::endl;
	//std::cout << b.getRawBits() << std::endl;
	//std::cout << c.getRawBits() << std::endl;
	return 0;
}