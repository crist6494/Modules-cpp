/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_cast.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:50:09 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:38:35 by cmorales         ###   ########.fr       */
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
		virtual void getNombre()
		{
			std::cout << "Hola que tal\n";
		}		
		virtual ~Padre(){};//Dynamic solo se usa a funciones polimorficas dinamicas
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

	Padre *p1 = new Derivada("Pepe", 55);//Tiempo de ejecucion

	Derivada *d1 = dynamic_cast<Derivada*>(p1); //Tiempo de ejecucion p1 es new == dinamic memory

	//Tiempo ejecuccion == puede fallar ahi que manejar los fallos
	if(d1)//Si falla dinamic cast se convierte en silencio nullptr
		d1->getNombre();
	else
		std::cout << "Puntero null\n";

    delete p1; // Con liberar uno es suficiente pq apunta a la misma direccion de memoria
} */