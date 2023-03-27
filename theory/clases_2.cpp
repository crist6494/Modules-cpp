//Sobrecarga de constructores

#include <iostream>

using namespace std;

class Fecha{
	private:
		int dia, mes ,año;
	public:
		Fecha(int,int,int);
		Fecha(long);
		void mostrar_fecha();
};

Fecha::Fecha(int _dia, int _mes, int _año){
	dia = _dia;
	mes = _mes;
	año = _año;
}

Fecha::Fecha(long fecha){
	año = int(fecha / 10000);
	mes = int(fecha - año * 10000) / 100;
	dia = int(fecha - año * 10000 - mes *100);

}

void Fecha::mostrar_fecha()
{
	cout<<"Hoy es dia "<<dia<<"/"<<mes<<"/"<<año<<endl;
}




int main()
{
	Fecha hoy(26, 3, 2023);
	Fecha ayer(2023325);
	hoy.mostrar_fecha();
	ayer.mostrar_fecha();
	return 0;
}
