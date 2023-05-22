/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:12:13 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/18 19:14:19 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor called from MateriaSource" << std::endl;
	for(int i = 0; i < 4; i++){
		this->_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called from MateriaSource" << std::endl;
	for(int i = 0; i < 4; i++){
		if(this->_materias[i])
			delete this->_materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "Copy constructor called from MateriaSource" <<std::endl;
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	std::cout << "Assignation operator called from MateriaSource" << std::endl;
	if(this != &src)
	{
		for(int i = 0; i < 4; i++){
			if(this->_materias[i])
				delete this->_materias[i];
			this->_materias[i] = src._materias[i];
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	unsigned int i = 0;

  	while(i < 4 && this->_materias[i] != NULL)
		i++;
	if(typeid(*m).name() == typeid(Ice).name())
	{
		std::cout << "Learn ice" << std::endl;
		this->_materias[i] = new Ice;
		*(this->_materias[i]) = *(m);
		return ;
	}
	else if(typeid(*m).name() == typeid(Cure).name())
	{
		std::cout << "Learn cure" << std::endl;
		this->_materias[i] = new Cure;
		*(this->_materias[i]) = *(m);
		return ;
	}
	else
		std::cout << "This materia doesn't exist" << std::endl;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++){
		if(_materias[i] && _materias[i]->getType() == type)
			return _materias[i]->clone();
	}
	return NULL;
}