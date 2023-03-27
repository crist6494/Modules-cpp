#include <iostream>

using namespace std;

class Rectangulo{
	private:
		float alto;
		float largo;
	public:
		Rectangulo(float, float); 
		void perimetro();
		void area();
};

Rectangulo::Rectangulo(float _alto, float _largo){
	alto = _alto;
	largo = _largo;
}

void Rectangulo::perimetro()
{
	float per;
	per = (2 * largo) + (2 * alto);
	cout<<"El perimetro del rectangulo es "<<per<<endl;
}

void Rectangulo::area()
{
	float ar;
	ar = alto * largo;
	cout<<"El area del rectagunlo es "<<ar<<endl;
}


//Instanciar una clase == crear un objeto
int main()
{
	Rectangulo r1(11, 4);

	r1.area();
	r1.perimetro();
	return 0;
}
