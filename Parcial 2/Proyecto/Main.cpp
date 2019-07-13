#include "Libraries_or_H.h"

using namespace std;


int main()
{
	//Variables
	unsigned int menu = 0;

	cout << "-----\t\t Inicio del programa \t\t-----" << endl;

	cout << "Ingresa\n 0- > Salir\n 1- > Ingresar una lista sencilla\n 2- > Ingresar una lista de doble enlace\n" << endl;
	cin >> menu;
	//Limpiamos la pantalla
	system("cls");
	if (!isdigit(menu))
	{
		switch (menu)
		{
			case 0:
				exit(0);
			case 1:
				menu_single();
				return main();
			case 2:
				menu_doble();
				return main();
		default:
			cout << "Ingresó un valor fuera de rango, ingrese uno valido" << endl;
			return main();
		}
	}
	else
	{
		cout << "Ingresa un numero entero" << endl;
		return main();
	}
	cin.get();
	cin.ignore();
	return 0;
}
