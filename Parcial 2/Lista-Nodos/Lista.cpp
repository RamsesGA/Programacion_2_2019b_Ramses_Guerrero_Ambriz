#include "Librerias_Clases.h"

using namespace std;

void Funcion_Lista()
{
	//Variables u objetos 
	int Contador = 0;
	int Numeros = 0;
	Lista Objeto;

	cout << "-----Inicio del programa-----" << endl;

	cout << "Ingresa la cantidad de elementos" << endl;
	cin >> Contador;
	cout << "Ingresa los numeros" << endl;
	for (int i = 0; i < Contador; i++)
	{
		cout << i + 1 << " - > ";
		cin >> Numeros;
		Objeto.Add_Lista(Numeros);
	}
	Objeto.Imprimir_Lista_Nodo();
	Objeto.Delete_Lista();
}

//Clase inicial y menu
int main()
{
	//Varibales
	unsigned char menu;
	//---------------------------------------------------------------

	cout << "Ingresa\n 0-Salir\n 1-Iniciar la lista de nodos" << endl;
	cin >> menu;

	//Funcion para limpiar la pantalla
	system("cls");
	//Controlador de decisiones
	switch (menu)
	{
		case '0':
			exit(0);
		case '1':
			Funcion_Lista();
			return main();
	default:
		cout << "Ingreso un dato erroneo, favor de ingresar un nuevo dato" << endl;
		return main();
	}
	return 0;
	cin.get();
	cin.ignore();
}