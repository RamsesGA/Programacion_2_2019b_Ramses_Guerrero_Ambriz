#pragma once
#include "Clases_Librerias.h"

using namespace std;

class Cola
{
public:
	//Atributos o miembros
	Nodo *PrimerNodo = nullptr;
	//Metodos
	Cola() {};

	//Funcion para crear un nodo y agregar datos
	void Add_Cola(int _num)
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
	void Imprimir_Cola_Nodo()
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
	void Delete_Cola()
	{
		delete PrimerNodo;
	}
};

