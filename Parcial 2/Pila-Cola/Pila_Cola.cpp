#include "Clases_Librerias.h"

using namespace std;

//Funcion para añadir datos en modo pila
void Funcion_Pila()
{
	//Variables u objetos
	Pila _Objeto;
	unsigned char seleccion;
	int Numero = 0; int Contador = 0;

	//Inicia el programa pidiendo la cantidad de datos a ingresar y estos datos
	cout << "Ingresa la cantidad a numeros a ingresar a la cubeta/pila" << endl;
	cin >> Contador;
	cout << "Ingresa un numero o numeros para agregar a la cubeta/pila" << endl;

	for (int i = 0; i < Contador; i++)
	{
		cout << i + 1 << " -> ";
		cin >> Numero;
		_Objeto.Add_Pila(Numero);
	}
	_Objeto.Imprimir_Pila_Nodo();
	_Objeto.Delete_Pila();
}

//Funcion para añadir datos en fila
void Funcion_Cola()
{
	//Variables u objetos
	Cola _Objeto;
	unsigned char seleccion;
	int Numero = 0; int Contador = 0;

	//Inicia el programa pidiendo la cantidad de datos a ingresar y estos datos
	cout << "Ingresa la cantidad a numeros a ingresar a la cubeta/pila" << endl;
	cin >> Contador;
	cout << "Ingresa un numero o numeros para agregar a la cubeta/pila" << endl;

	for (int i = 0; i < Contador; i++)
	{
		cout << i + 1 << " -> ";
		cin >> Numero;
		_Objeto.Add_Cola(Numero);
	}
	_Objeto.Imprimir_Cola_Nodo();
	_Objeto.Delete_Cola();
}

//Funcion principal
int main()
{
	unsigned char seleccion;

	cout << "Selecciona\n 0-Salir\n 1-Pila\n 2-Cola" << endl;
	cin >> seleccion;

	switch (seleccion)
	{
		case '0':
			exit(0);
		case '1':
			Funcion_Pila();
			return main();
		case '2':
			Funcion_Cola();
			return main();
	default:
		cout << "Valor incorrecto, ingrese un dato valido" << endl;
		return main();
	}

	cin.get();
	cin.ignore();
	return 0;
}