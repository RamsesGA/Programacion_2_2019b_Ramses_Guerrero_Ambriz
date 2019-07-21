#include "Libraries.h"
#include "Node.h"

void tree()
{
	string last;
	string name;

	unsigned int cont = 0;
	unsigned int age;
	unsigned int menu = 1;

	Node obj;
	Node *n_tree = nullptr;

	cout << "\n---Arboles---" << endl;

	if (!isdigit(menu))
	{
		while (menu != 0)
		{
			switch (menu)
			{
				case 1:
					cout << "Nodo - - > " << cont << endl;

					cout << "\nIngresa un apellido" << endl;
					cin >> last;
					cout << "\nIngresa un nombre" << endl;
					cin >> name;
					cout << "\nIngresa una edad" << endl;
					cin >> age;

					//Llamamos a la funci�n
					obj.insert_node(n_tree, last, name, age);
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
	cout << "Ingresa \n0-In order \n1-Pre order \n2-Post order" << endl;
	cin >> menu;

	//Limpiamos la pantalla
	system("cls");
	switch (menu)
	{
		case 0:
			cout << "\n--- > In Order <---" << endl;
			while (menu == 0)
			{
				obj.in_order(n_tree);
				menu++;
			}
			break;
		case 1:
			cout << "\n--- > Pre Order <---" << endl;
			while (menu == 1)
			{
				obj.pre_order(n_tree);
				menu++;
			}
			break;
		case 2:
			cout << "\n--- > Post Order <---" << endl;
			while (menu == 2)
			{
				obj.post_order(n_tree);
				menu++;
			}
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