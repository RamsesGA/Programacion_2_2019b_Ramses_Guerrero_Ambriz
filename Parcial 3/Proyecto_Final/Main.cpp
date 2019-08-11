#include <iostream>
#include <string>
#include "Arbol_AVL.h"
#include "Persona.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int arbol_avl();

int main()
{

	unsigned int menu = 0;

	cout << "\nIngresa \n0-Salir \n1-Para un arbol binario \n2-Para un arbol binario AVL" << endl;
	cin >> menu;

	switch (menu)
	{
		case 0:
			exit(0);
		//Caso para el arbol binario
		case 1:
			system("cls");

			return main();

		//Caso para el arbol binario AVL
		case 2:
			system("cls");
			arbol_avl();
			return main();


		default:
			system("cls");
			cout << "Ingresa un valor correcto" << endl;
			return main();
	}

	cin.get();
	cin.ignore();
	return 0;
}

//Funci�n menu para el �rbol binario (sin AVL)
int arbol_avl()
{
	char eleccion;
	Arbol_AVL<Persona>*nodo_nuevo = new Arbol_AVL<Persona>();
	unsigned int forzar_salida = 0;

	while (forzar_salida == 0)
	{
		system("cls");
		cout << "0 -- > Salir\n\n";
		cout << "1 -- > Agregar un elemento\n\n";
		cout << "2 -- > Mostrar el arbol in_orden\n\n";
		cout << "3 -- > Mostrar el arbol pre_orden\n\n";
		cout << "4 -- > Mostrar el arbol post_orden\n\n";
		cout << "5 -- > Revisar si el arbol esta balanceado\n\n";
		cout << "6 -- > Eliminar un nodo\n\n";
		cout << "7 -- > Rotar el arbol\n\n";
		cin >> eleccion;

		switch (eleccion)
		{

			case '0':
				exit(0);

			//ingresar nodos
			case '1':
			{
				//Limpiamos la pantalla
				system("cls");

				//User * U = new User(Nombre, Apellido, Edad);
				Nodos<Persona>*nodo_temp = new Nodos<Persona>(Persona());
				nodo_nuevo->ingresar(nodo_temp);
				break;
			}

			//mostrar arbol en inorden
			case '2':
				//Limpiamos la pantalla
				system("cls");

				nodo_nuevo->in_orden();
				forzar_salida++;
				break;

			//mostrar arbol en preorden
			case '3':
				//Limpiamos la pantalla
				system("cls");

				nodo_nuevo->pre_orden();
				forzar_salida++;
				break;

			//mostrar arbol en postorden
			case '4':
				//Limpiamos la pantalla
				system("cls");

				nodo_nuevo->post_orden();
				forzar_salida++;
				break;

			//Mostrar si el arbol esta balanceado
			case '5':
				//Limpiamos la pantalla
				system("cls");

				nodo_nuevo->balance();
				forzar_salida++;
				break;

			//eliminar el nodo que el usuario ingrese
			case '6':
			{
				//Limpiamos la pantalla
				system("cls");

				//Creamos un nuevo nodo el cual nodo_temp va a tener el nombre, apellido y edad
				Nodos<Persona>*nodo_temp = new Nodos<Persona>(Persona());

				//Finalmente nodo_nuevo va 
				nodo_nuevo->eliminar(nodo_temp);
				forzar_salida++;
				break;
			}

			case '7':
				nodo_nuevo->rotacion();
				forzar_salida++;
				break;

			default:
				system("cls");
				cout << "\nIngresa un valor correcto" << endl;
				return arbol_avl();
		}
	}
}