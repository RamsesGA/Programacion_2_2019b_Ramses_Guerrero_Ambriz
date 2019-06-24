#include "Clases_Librerias.h"

//Funcion para crear un nodo y agregar datos
void Pila::Add_Pila(int _num)
{
	if (PrimerNodo != nullptr)
	{
		Nodo *Temporal = PrimerNodo;
		PrimerNodo = new Nodo(_num);
		PrimerNodo->SiguienteNodo = Temporal;
	}
	else
	{
		PrimerNodo = new Nodo(_num);
	}
}

//Funcion para mandar a llamar a la funcion imprimir del nodo
void Pila::Imprimir_Pila_Nodo()
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
void Pila::Delete_Pila()
{
	delete PrimerNodo;
}

