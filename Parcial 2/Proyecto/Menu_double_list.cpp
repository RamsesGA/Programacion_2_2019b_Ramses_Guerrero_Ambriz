#include "Libraries_or_H.h"

using namespace std;

void menu_doble()
{
	unsigned int cont = 0;
	string name;
	unsigned char day;
	unsigned char month;
	unsigned char year;

	cout << "-----\t\t Menu Double List \t\t-----" << endl;

	cout << "Ingresa una cantidad de datos(numero)" << endl;
	cin >> cont;
	if (isdigit(cont))
	{
		system("cls");
		for (int i = 0; i < cont; i++)
		{
			DoubleNode *nodo = new DoubleNode();
			cout << "Nodo : " << i + 1 << endl;
			cin >> *nodo;
		}
	}
	else
	{
		cout << "Ingresa un valor correcto, porfavor" << endl;
		return menu_single();
	}
	//Mandamos a llamar la función 
	system("cls");
	
}
