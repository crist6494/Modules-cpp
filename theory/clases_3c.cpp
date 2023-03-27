//Destructor de un objeto

#include <iostream>

using namespace std;

class Perro{
	private:
		char * nombre;
		char * raza;
	public:
		Perro(char *, char *);
		~Perro();
		void mostrarDatos();
		void jugar();
};

Perro::Perro(char *_nombre, char *_raza)
{
	nombre = _nombre;
	raza = _raza;
}
Perro::~Perro(){
}

void Perro::mostrarDatos()
{
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Raza: "<<raza<<endl;
}

void Perro::jugar()
{
	cout<<"El perro esta jugando"<<endl;
}

//Instanciar una clase == crear un objeto
int main()
{
	Perro p1("Bobi", "Rottweiler");

	p1.mostrarDatos();
	p1.jugar();
	p1.~Perro();//Destruye el objeto
	return 0;
}
