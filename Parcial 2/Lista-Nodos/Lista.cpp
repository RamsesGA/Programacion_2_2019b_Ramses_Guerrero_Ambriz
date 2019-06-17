#include "Librerias_Clases.h"

using namespace std;

void Funcion_Lista()
{
	Nodo *Informacion = nullptr;
	Nodo *Puntero = nullptr;
	int Valores = 0;
	int Contador = 0;
	cout << "-----Inicio del programa-----" << endl;

	cout << "Ingresa la cantidad de elementos" << endl;
	cin >> Contador;
	cout << "Ingresa los numeros" << endl;

	//Ciclo para emepzar a ingresar los datos a los nodos
	for (int i = 0; i < Contador; i++)
	{
		cout << i + 1 << " -> ";
		cin >> Contador;
		Informacion = Puntero->Crear_Nodo(Informacion, Valores);
	}

	//Instruccion para mandar a imprimir los datos
	Puntero->Imprimir_Datos(Informacion);
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