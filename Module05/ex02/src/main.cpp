/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:00:05 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/12 20:13:00 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Jesus", 32);
	AForm f("Form", 45, 32);
	std::cout << b;
	std::cout << f;
}