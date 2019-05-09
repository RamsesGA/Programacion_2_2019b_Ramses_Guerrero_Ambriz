#include "Librerias.h"

using namespace std;

vector <int> burbuja(vector <int> cant, int longitud)
{
	int r1 = 0;
	//Ciclo para acomodar
	for (int i = 0; i < longitud; i++)
	{
		for (int j = 0; j < longitud - 1; j++)
		{
			if (cant[j] > cant[j + 1])
			{
				r1 = cant[j];
				cant[j] = cant[j + 1];
				cant[j + 1] = r1;
			}
		}
	}
	return cant;
}
int main()
{
	unsigned char valor;
	unsigned int longi = 0;
	vector <int> final;

	cout << "Ingresa 1 para iniciar" << endl;
	cin >> valor;

	if (valor == '1')
	{
		cout << "Ingresa la longitud" << endl;
		cin >> longi;
		vector <int> datos(longi);
		cout << "Ingresa los datos" << endl;
		//Ciclo para ingresar datos
		for (int i = 0; i < size(datos); i++)
		{
			cin >> datos[i];
		}
		final = burbuja(datos, longi);
		for (int i = 0; i < final.size(); i++)
		{
			cout << final[i] << " ";
		}
	}
	if (valor != '1')
	{
		exit(0);
	}
	cin.get();
	cin.ignore();
	return 0;
}