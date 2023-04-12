/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:21:27 by cmorales          #+#    #+#             */
/*   Updated: 2023/04/12 17:27:31 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


std::string get_content_file(std::string filename)
{
	std::ifstream file;
	std::string aux;
	std::string line;
	const char	*filename_char = filename.c_str();
	
	file.open(filename_char, std::ios::in);
	if(!file.is_open())
		std::cout << "Error: File cannot be opened"<< std::endl;
	else
	{
		while(getline(file, line))
			aux += line + "\n";
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

	file = get_content_file(filename);
	filename = filename + ".replace";
	const char	*filename_char = filename.c_str();
	out_file.open(filename_char);
	if(!out_file.is_open())
		std::cout << "Error: File cannot be opened"<< std::endl;
	else
	{
		while((n_find = file.find(s1)) != std::string::npos)
		{
			aux = file.substr(n_find + s1.size());
			file.erase(n_find);
			file += s2 + aux;
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