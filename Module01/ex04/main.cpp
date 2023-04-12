/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:21:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/12 01:10:17 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string get_content_file(std::string filename)
{
	std::ifstream file;
	std::string aux;
	const char* lynux_filename = filename.c_str();
	
	file.open(lynux_filename, std::ios::in);
	if(!file.is_open())
		std::cout << "Error: File cannot be opened"<< std::endl;
	else
	{
		getline(file, aux);
		file.close();
	}
	return aux;
}

void replace_string(std::string filename, std::string s1, std::string s2)
{
	std::string file;
	std::string aux;
	std::ofstream out_file;
	size_t	n_find;

	(void)s2;
	file = get_content_file(filename);
	filename = filename + ".replace";
	const char* lynux_filename = filename.c_str();
	out_file.open(lynux_filename);
	if(!out_file.is_open())
		std::cout << "Error: File cannot be opened"<< std::endl;
	else
	{
		//int last = 0;
		while((n_find = file.find(s1)) != std::string::npos)
		{
			aux = file.substr(n_find + s1.size());
			file.erase(n_find);
			file += s2 + aux;
			//last = n_find + s2.size();
		}
		out_file << file;
		out_file.close();
	}
}

int main(int ac, char **av)
{
	if(ac == 4)
	{
		std::string filename = av[1];
		std::string aux = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		

		replace_string(filename, s1, s2);
	}
	else
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
}