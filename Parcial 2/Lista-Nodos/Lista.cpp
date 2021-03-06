#include "Librerias_Clases.h"

//Librerias Chrono o timer para checar cuanto tardan
using namespace std;

//1-Funcion para poder ingresar nodos con datos
void Funcion_lista()
{
	Lista_Linkeada_Clase objeto;
	int dato = 0;
	int input = 0;
	int contador_Front = 0;
	int contador_Back = 0;
	int longitud_Final = 0;
	int controlador = 0;

	//Inicio del programa, para crear nodos e ingresar datos a estos
	cout << "Ingresa la cantidad de datos a ingresar en Front" << endl;
	cin >> contador_Front;
	cout << "Ingresa los datos: " << endl;
	//Ciclo para poder crear nodos y asignarles su dato correspondiente hacia adelante
	for (int i = 0; i < contador_Front; i++)
	{
		cout << i + 1 << " - - > ";
		cin >> dato;
		objeto.add_Front(dato);
	}
	//Funci�n para crear nodos e ingresar datos a estos
	cout << "Ingresa la cantidad de datos a ingresar en Back" << endl;
	cin >> contador_Back;
	cout << "Ingresa los datos: " << endl;
	//Ciclo para poder crear nodos y asignarles su dato correspondiente hacia atras
	for (int i = 0; i < contador_Back; i++)
	{
		cout << i + 1 << " - - > ";
		cin >> dato;
		objeto.add_Back(dato);
	}
	//Se almacena la longitud
	longitud_Final = contador_Front + contador_Back;
	//Se hace una limpieza de pantalla
	system("cls");
	//Imprimimos el resultado para corroborar que no hay problemas
	cout << "\nLos valores de Inicio a Fin y Fin a Inicio: " << endl;
	//Mandamos a llamar las funciones
	cout << "- - > ";
	objeto.print_Forward();
	cout << '\n';
	cout << "- - > ";
	objeto.print_Reverse();

	//Un peque�o menu para empezar la siguiente parte del programa las opciones son:

	cout << "\nIngresa\n 1- - >Para ingresar un nuevo nodo\n 2- - >Para eliminar un nodo\n 3- - >Para el ordenamiento bubblesort\n 4- - >Para el ordenamiento quicksort" << endl;
	cin >> controlador;
	//Funcion para limpiar la pantalla
	system("cls");
	switch (controlador)
	{
		case 1:
			//Solo se imprime para comparar
			cout << "\nLos datos actuales son :" << endl;
			objeto.print_Forward();
			//Est� parte es para poder ingresar un dato extra, pedimos el dato a ingresar 
			cout << "\nIngresa la posicion" << endl;
			cin >> input;
			//Despues pedimos la ubicaci�n donde quiere ingresar el nuevo nodo
			cout << "\nIngresa el numero nuevo" << endl;
			cin >> dato;
			objeto.add_X(input, dato);
			//Se imprime, para checar si el dato se ingres�
			cout << "\nLos datos actuales son :" << endl;
			cout << "- - > ";
			objeto.print_Forward();
			break;
		case 2:
			//Solo se imprime para comparar
			objeto.print_Forward();
			//Est� parte es para poder ingresar un valor y buscarlo para borrar
			cout << "\nIngresa la posicion" << endl;
			cin >> input;
			objeto.remove_X(input);
			//Se imprime, para checar si el nodo se elimin�
			cout << "\nLos valores de Inicio a Fin, son :" << endl;
			cout << "- - > ";
			objeto.print_Forward();
			break;
		case 3:
			cout << "Antes - - > ";
			objeto.print_Forward();
			Bubble(objeto.n_Header->p_Next, objeto.n_Trailer);
			cout << "Ahora - - >";
			objeto.print_Forward();
			break;
		case 4:
			cout << "En proceso" << endl;
			//Add_data_quick(objeto.n_Header);
			break;
	default:
		cout << "Ingreso un valor erroneo, el programa se va a cerrar" << endl;
		break;
	}

}

//Clase inicial y menu
int main()
{
	//Varibales
	unsigned char menu;

	cout << "\nIngresa:\n 0- - >Salir\n 1- - >Iniciar la lista de nodos" << endl;
	cin >> menu;

	//Funcion para limpiar la pantalla
	system("cls");
	//Controlador de decisiones
	switch (menu)
	{
		case '0':
			exit(0);
		case '1':
			Funcion_lista();
			return main();
	default:
		cout << "Ingreso un dato erroneo, favor de ingresar un nuevo dato" << endl;
		return main();
	}
	return 0;
	cin.get();
	cin.ignore();
}