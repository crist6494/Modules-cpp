/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_cast.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorales <cmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:04:59 by cmorales          #+#    #+#             */
/*   Updated: 2023/10/26 20:39:25 by cmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Padre
{
	protected:
		std::string _nombre;
	public:
		Padre(std::string nombre)
			:_nombre(nombre){}
		void getNombre()
		{
			std::cout << "Mi nombre es " << this->_nombre << std::endl;
		}		
		~Padre(){};
};

class Derivada: public Padre
{
	private:
		std::string _childname;
	public:
		Derivada(std::string nombre, std::string childname)
			:Padre(nombre), _childname(childname)
		{
		}
		void getNombre()
		{
			std::cout << "Mi nombre es " << this->_nombre << " y tengo " << this->_childname << std::endl;
		}
		~Derivada(){}
};

/* int main()
{
    Padre p("Padre");
	Derivada d("Padre", "Derivada");
    
	p.getNombre();
	d.getNombre();
    
    std::cout << "---------------\n";

	Padre *p1 = &d;
	Derivada *d1 = static_cast<Derivada*>(p1); //Tiempo de ejecucion p1 es new == dinamic memory
    
    p1->getNombre();
	d1->getNombre();
} */