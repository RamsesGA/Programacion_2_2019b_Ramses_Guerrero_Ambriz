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

//Función menu para el árbol binario (sin AVL)
int arbol_avl()
{
	char eleccion;
	Arbol_AVL<Persona>*node = new Arbol_AVL<Persona>();
	unsigned int force_exit = 0;

	while (force_exit == 0)
	{
		system("cls");
		cout << "0 -- > Salir\n\n";
		cout << "1 -- > Agregar un elemento\n\n";
		cout << "2 -- > Mostrar el arbol Inorden\n\n";
		cout << "3 -- > Mostrar el arbol Preorden\n\n";
		cout << "4 -- > Mostrar el arbol Postorden\n\n";
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
				Nodes<Persona>*node_temp = new Nodes<Persona>(Persona());
				node->Push(node_temp);
				break;
			}

			//mostrar arbol en inorden
			case '2':
				//Limpiamos la pantalla
				system("cls");

				node->Inorden();
				force_exit++;
				break;

			//mostrar arbol en preorden
			case '3':
				//Limpiamos la pantalla
				system("cls");

				node->Preorden();
				force_exit++;
				break;

			//mostrar arbol en postorden
			case '4':
				//Limpiamos la pantalla
				system("cls");

				node->Postorden();
				force_exit++;
				break;

			//Mostrar si el arbol esta balanceado
			case '5':
				//Limpiamos la pantalla
				system("cls");

				node->Balance();
				force_exit++;
				break;

			//eliminar el nodo que el usuario ingrese
			case '6':
			{
				//Limpiamos la pantalla
				system("cls");

				//Creamos un nuevo nodo el cual node_temp va a tener el nombre, apellido y edad
				Nodes<Persona>*node_temp = new Nodes<Persona>(Persona());

				//Finalmente node va 
				node->Pull(node_temp);
				force_exit++;
				break;
			}

			case '7':
				node->Rotacion();
				force_exit++;
				break;

			default:
				system("cls");
				cout << "\nIngresa un valor correcto" << endl;
				return arbol_avl();
		}
	}
}