#include "Clases_Librerias.h"

//Funcion para crear un nodo y agregar datos
void Cola::Add_Cola(int _num)
{
	if (PrimerNodo != nullptr)
	{
		Nodo *Temporal = new Nodo(_num);
		PrimerNodo->Add_Nodo(Temporal);
	}
	else
	{
		PrimerNodo = new Nodo(_num);
	}
}
//Funcion para mandar a llamar a la funcion imprimir del nodo
void Cola::Imprimir_Cola_Nodo()
{
	if (PrimerNodo != nullptr)
	{
		PrimerNodo->Imprimir_Nodo();
	}
	else
	{
		cout << "No hay datos, gomen gomen uwu" << endl;
	}
}
//Funcion para eliminar los datos
void Cola::Delete_Cola()
{
	delete PrimerNodo;
}
