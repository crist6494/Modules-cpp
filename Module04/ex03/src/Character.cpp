/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:11:47 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/21 17:17:36 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name)
	:_name(name)
{
	std::cout << "Constructor with 1 parameter <string> called from Character: " << this->_name << std::endl;
	del_list = NULL;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::Character()
	:_name("")
{
	std::cout << "Default constructor called from Character: NO NAME"<<std::endl;
	del_list = NULL;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << "Destructor called from Character: " << this->_name << std::endl;
	if(del_list != NULL)
		removeList();
	for(int i = 0; i < 4; i++){
		if(this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character::Character (Character const &src)
{
	
	del_list = NULL;
	copyDeleteList(src.del_list);
	for(unsigned int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	*this = src;
}

Character& Character::operator=(const Character& src)
{
	if(this != &src)
	{
		this->_name = src._name;
		std::cout << "Assignation operator called from Character: " << this->_name << std::endl;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
				this->_inventory[i] = src._inventory[i]->clone();
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if(m == NULL)
	{
		std::cout << "Materia don't exist" << std::endl;
		return ;
	}
	for(int i = 0; i < 4; i++){
		if(this->_inventory[i] == NULL)
		{
			if(typeid(*m).name() == typeid(Ice).name())
			{
				std::cout << "Equipped assigning ice" << std::endl;
				this->_inventory[i] = new Ice;
				*(this->_inventory[i]) = *(m);
				return ;
			}
			else if(typeid(*m).name() == typeid(Cure).name())
			{
				std::cout << "Equipped assigning cure" << std::endl;
				this->_inventory[i] = new Cure;
				*(this->_inventory[i]) = *(m);
				return ;
			}
		}
	}
    std::cout << "Character: " << this->_name << " can't equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if(idx >= 4 || idx < 0)
    {
        std::cout<<"Index is not in range"<<std::endl;
    }
	else if(this->_inventory[idx])
	{
		addElementDelete(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
		std::cout << "Character: " << this->_name << " unequipped correctly" << std::endl;
	}
	else
		std::cout << "Character: " << this->_name << " can't unequipped" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if(this->_inventory[idx])
	{
		this->_inventory[idx]->use(target);
		std::cout << "Character: " << this->_name << " uses " << this->_inventory[idx]->getType() << std::endl;
	}
	else
		std::cout << "Character: " << this->_name << " can't use this inventary" << std::endl; 
}

void Character::addElementDelete(AMateria *materia)
{
	t_materias *aux;
	
	aux = new t_materias;
	aux->materia = materia;
	aux->nxt = del_list;
	del_list = aux;
}

void Character::removeList(void)
{
	t_materias *aux;

	while(del_list != NULL)
	{
		delete del_list->materia;
		aux = del_list;
		del_list = del_list->nxt;
		delete aux;
	}
}

void Character::copyDeleteList(t_materias *dl)
{

	t_materias *aux, *aux2;
	if(dl == NULL)
	{
		return ;
	}
	else
	{	
		aux = dl;
		del_list = new t_materias;
		del_list->nxt = NULL;
		aux2 = del_list;
		while(aux != NULL)
		{
			if(typeid(*(aux->materia)).name() == typeid(Ice).name())
			{
				std::cout<<"Assigning ice"<<std::endl;
				aux2->materia = new Ice();
				*(aux2->materia) = *(aux->materia);
				aux2->nxt = NULL;
			}
			else if(typeid(*(aux->materia)).name() == typeid(Cure).name())
			{
				std::cout<<"Assigning cure"<<std::endl;
				aux->materia = new Cure();
				*(aux2->materia) = *(aux->materia);
				aux = NULL;
			}
			aux = aux->nxt;
			if(aux != NULL)
			{
				aux2->nxt = new t_materias;
				aux2 = aux2->nxt;
			}	
		}
	}	
}
