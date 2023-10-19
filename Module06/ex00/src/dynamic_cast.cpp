/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_cast.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <moralesrojascr@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:50:09 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/19 20:41:20 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Padre
{
	private:
		std::string _nombre;
	public:
		Padre(std::string nombre)
			:_nombre(nombre){}
		void getNombre()
		{
			std::cout << "Hola que tal\n";
		}		
		virtual ~Padre(){};
};

class Derivada: public Padre
{
	private:
		int _edad;
	public:
		Derivada(std::string nombre, int edad)
			:Padre(nombre), _edad(edad)
		{
		}
		void getNombre()
		{
			std::cout << "Mi nombre es el de mi padre y tengo " << this->_edad << std::endl;
		}
		~Derivada(){}
};


/* int main()
{
	Derivada d("Juan", 3);
    Padre* p = &d;
	p->getNombre();

	//Padre *p1 = new Padre("Pepe");
	Padre *p1 = new Derivada("Pepe", 55);

	Derivada *d1 = dynamic_cast<Derivada*>(p1);

	if(d1)
		d1->getNombre();
	else
		std::cout << "Puntero null\n";

   // delete p; // No olvides liberar la memoria asignada con new
} */