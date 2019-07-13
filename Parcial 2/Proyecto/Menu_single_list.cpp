#include "Libraries_or_H.h"

using namespace std;

void menu_single()
{
	unsigned int menu = 0;
	unsigned int pos = 0;
	SingleList obj;
	string name;
	system("cls");
	cout << "-----\t\t Menu Single List \t\t-----" << endl;

	cout << "Ingresa\n 0-Salir\n 1-Push\n 2-Push (posicion)\n 3-Pull\n 4-Pull (posicion)\n 5-Remove\n 6-Remove (posicion)" << endl;
	cout << " 7-Clear\n";
	cin >> menu;
	SingleNode *node = new SingleNode();
	switch (menu)
	{
		case 0:
			exit(0);

		case 1:
			cin >> *node;
			obj.push(node);	
			return menu_single();

		case 2:
			cout << "Ingresa una posicion" << endl;
			cin >> pos;

			if (isdigit(pos))
			{
				cin >> *node;
				obj.push(node, pos);
			}
			else
			{
				cout << "Ingresa un valor entero" << endl;
				return menu_single();
			}
			return menu_single();

		case 3:
			cin >> *node;
			obj.pull();
			return menu_single();

		case 4:
			cout << "Ingresa una posicion" << endl;
			cin >> pos;

			if (isdigit(pos))
			{
				cin >> *node;
				obj.pull(pos);
			}
			else
			{
				cout << "Ingresa un valor entero" << endl;
				return menu_single();
			}
			return menu_single();
			
		case 5:
			cin >> *node;
			obj.remove();
			return menu_single();

		case 6:
			cout << "Ingresa una posicion" << endl;
			cin >> pos;

			if (isdigit(pos))
			{
				cin >> *node;
				obj.remove(pos);
			}
			else
			{
				cout << "Ingresa un valor entero" << endl;
				return menu_single();
			}
			return menu_single();			

		case 7:
			cin >> *node;
			obj.clear();
			return menu_single();

	default:
		cout << "Ingresa un valor entero" << endl;
		return menu_single();
	}
}
