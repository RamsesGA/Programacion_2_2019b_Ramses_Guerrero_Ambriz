#include "Libraries.h"
#include "Node.h"
#include "Tree.h"
#include "Person.h"

void tree()
{
	string last;
	string name;

	unsigned int cont = 0;
	unsigned int age;
	unsigned int menu = 1;

	Tree<Person> *arbol = new Tree<Person>();
	Node<Person> *creacion;

	cout << "\n---Arboles---" << endl;

	if (!isdigit(menu))
	{
		while (menu != 0)
		{
			switch (menu)
			{
			case 1:
				cout << "Nodos creados - - > " << cont << endl;
				//Creamos un nodo el cual va a incluir los datos de una persona
				creacion = new Node<Person>(Person());

				//Se manda a llamar la funci�n insert, ubicado en Tree.h
				arbol->insert(creacion);


				cont++;

				cout << "\nIngresa 0 Para terminar o 1 Para continuar" << endl;
				cin >> menu;

				//Limpiamos la pantalla
				system("cls");

				break;
			default:
				cout << "\nIngresa un valor correcto" << endl;
				return tree();
			}
		}
	}

	//Segundo menu
	cout << "Cantidad de nodos - - > " << cont << endl;
	cout << "\nMenu para la impresion" << endl;
	cout << "Ingresa \n0-In order \n1-Pre order \n2-Post order \n3-Checar si el arbol esta equilibrado" << endl;
	cout << "4-Eliminar una hoja/raiz \n5-Rotacion" << endl;
	cin >> menu;
	Node<Person> *temp = nullptr;
	//Limpiamos la pantalla
	system("cls");
	switch (menu)
	{
		case 0:
			cout << "\n--- > In Order <---" << endl;
			while (menu == 0)
			{
				arbol->in_order_tree();
				menu++;
			}
			break;

		case 1:
			cout << "\n--- > Pre Order <---" << endl;
			while (menu == 1)
			{
				arbol->pre_order_tree();
				menu++;
			}
			break;

		case 2:
			cout << "\n--- > Post Order <---" << endl;
			while (menu == 2)
			{
				arbol->post_order_tree();
				menu++;
			}
			break;

		case 3:
			cout << "\n--- > Arbol equilibrado <---" << endl;
			arbol->check_tree();
			break;

		case 4:
			cout << "\n--- > Eliminar hoja/raiz <---" << endl;

			cout << "Ingresa los datos siguientes" << endl;
			temp = new Node<Person>(Person());
			arbol->eliminate_in_tree(temp);
			arbol->in_order_tree();
			break;

		case 5:
			cout << "\n--- > Rotacion <---" << endl;
			
			break;

		default:
			cout << "\nIngresa un valor correcto" << endl;
			return tree();
	}
}



int main()
{
	unsigned int menu = 0;

	cout << "\n-- Programa: CARGA DE ARBOLES --" << endl;

	cout << "\nIngresa \n0-Salir \n1-Iniciar" << endl;
	cin >> menu;

	//Limpiamos la pantalla
	system("cls");
	switch (menu)
	{
		case 0:
			exit(0);
		case 1:
			tree();
			return main();
	default:
		cout << "\nIngrese un dato valido" << endl;
		return main();
	}
	cin.get();
	cin.ignore();
	return 0;
}