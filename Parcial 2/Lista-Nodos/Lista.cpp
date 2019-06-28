#include "Librerias_Clases.h"

using namespace std;

//3-Funcion de ordenamiento
void Super_QuickSort(Nodo _arreglo[], int _izquierda, int _derecha)
{
	//Puntero incial del lado menor
	int i = _izquierda;
	//Puntero inicial del lado mayor
	int j = _derecha;
	//Variable para almacenar un dato necesario a intercambiar
	int tempo = 0;
	//Pivote central
	int pivote = _arreglo[(_izquierda + _derecha) / 2];
}

//1-Funcion para poder ingresar nodos con datos
void Funcion_Lista()
{
	Lista_Linkeada_Clase objeto;
	int dato = 0;
	int contador_Front = 0;
	int contador_Back = 0;
	int longitud_Final = 0;

	cout << "Ingresa la cantidad de datos a ingresar en Front" << endl;
	cin >> contador_Front;
	cout << "Ingresa los datos: " << endl;
	for (int i = 0; i < contador_Front; i++)
	{
		cout << i + 1 << " - - > ";
		cin >> dato;
		objeto.add_Front(dato);
	}
	cout << "Ingresa la cantidad de datos a ingresar en Back" << endl;
	cin >> contador_Back;
	cout << "Ingresa los datos: " << endl;
	for (int i = 0; i < contador_Back; i++)
	{
		cout << i + 1 << " - - > ";
		cin >> dato;
		objeto.add_Back(dato);
	}

	system("cls");
	//Terminamos imprimiendo
	cout << "\nLos valores de Inicio a Fin, son : " << endl;
	objeto.print_Forward();
	cout << "\nLos valores de Fin a Inicio, son : " << endl;
	objeto.print_Reverse();

	longitud_Final = contador_Front + contador_Back;
	//Se declara un arreglo dinámico
	Nodo *arreglo_din = new Nodo[longitud_Final];
	int contador = 0;
	//Iniciamos con el paso 2
	Add_Datos_Arreglo(arreglo_din, longitud_Final, contador, objeto.n_Header);
	//Paso 3
	Super_QuickSort(arreglo_din, 0, longitud_Final - 1);

}

//2-Funcion para poder añadir los punteros al nuevo arreglo
void Add_Datos_Arreglo(Nodo _arreglo[], int &_longitud, int &_contador, Nodo *_header)
{
	if (_contador < _longitud)
	{
		_arreglo[_contador] = *_header;
		if (_header->p_Next != nullptr)
		{
			_contador++;
			Add_Datos_Arreglo(_arreglo, _longitud, _contador, _header->p_Next);
		}
	}
}

//Clase inicial y menu
int main()
{
	//Varibales
	unsigned char menu;

	cout << "\nIngresa\n 0-Salir\n 1-Iniciar la lista de nodos" << endl;
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