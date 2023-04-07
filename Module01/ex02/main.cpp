/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:11:33 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/07 17:15:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string *dir_s1 = &s;
	std::string &ref_s1 = s;
	
	std::cout << "Memory address of string: " << &s << std::endl;
	std::cout << "Memory address of stringPTR: " << dir_s1 << std::endl;
	std::cout << "Memory address of stringREF: " << &ref_s1 << std::endl<<std::endl;

	std::cout << "Value of string: " << s << std::endl;
	std::cout << "Value of stringPTR: " << *dir_s1 << std::endl;
	std::cout << "Value of stringREF: " << ref_s1 << std::endl;
	
}