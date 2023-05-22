/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:11:47 by cmorales          #+#    #+#             */
/*   Updated: 2023/05/22 20:41:27 by cmorales         ###   ########.fr       */
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

Character::Character (const Character &src)
{
	del_list = NULL;
	copyDeleteList(src.del_list);
	for(unsigned int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
	*this = src;
	std::cout<<"Copy constructor called from Character: " << this->_name <<std::endl;
}

Character& Character::operator=(const Character& src)
{
	if(this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
				if(this->_inventory[i] == NULL)
				{
					if(typeid(*(src._inventory[i])).name() == typeid(Ice).name())
					{
						std::cout<<"Assigning ice"<<std::endl;
						this->_inventory[i] = new Ice();
						*(this->_inventory[i]) = *(src._inventory[i]);
					}
					else if(typeid(*(src._inventory[i])).name() == typeid(Cure).name())
					{
						std::cout<<"Assigning cure"<<std::endl;
						this->_inventory[i] = new Cure();
						*(this->_inventory[i]) = *(src._inventory[i]);
					}
					else
					{
						std::cout<<"Non existing AMateria"<<std::endl;
					}
				}
			}
		}
	}
	std::cout << "Assignation operator called from Character: " << this->_name << std::endl;
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

/*Guarada memoria para crear la lista, asigna la materia y el nxt y lo añade a la lista*/
void Character::addElementDelete(AMateria *materia)
{
	t_materias *aux;
	
	aux = new t_materias;
	aux->materia = materia;
	aux->nxt = del_list;
	del_list = aux;
}

/*Libera la clases materia y luego el la lista con el aux*/
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

/*Copiar la lista de borrar en el constructor de copia aux es 
de la lista y aux2 la refenrecia donde se va a copiar*/
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
				aux2->materia = new Cure();
				*(aux2->materia) = *(aux->materia);
				aux2->nxt = NULL;
			}
			//Verificamos si hay algun elemento en la lista
			//si lo hay se guarda memoria para el sig y se avanza
			aux = aux->nxt;
			if(aux != NULL)
			{
				aux2->nxt = new t_materias;
				aux2 = aux2->nxt;
			}	
		}
	}	
}
