#pragma once
#include "Librerias_Clases.h"

using namespace std;

class Lista
{
public:
	//Atributos - miembros
	Nodo *Primer_Nodo = nullptr;

	//Metodos - constructores
	Lista() {};

	//Funcion para crear un nodo y agregar datos
	void Add_Lista(int _Num)
	{
		if (Primer_Nodo != nullptr)
		{
			Nodo *Temporal = Primer_Nodo;
			Primer_Nodo = new Nodo(_Num);
			Primer_Nodo->Nodo_Siguiente = Temporal;
		}
		else
		{
			Primer_Nodo = new Nodo(_Num);
		}
	}

	//Funcion para mandar a llamar la funcion de imprimir_nodo
	void Imprimir_Lista_Nodo()
	{
		if (Primer_Nodo != nullptr)
		{
			Primer_Nodo->Imprimir_Nodo();
		}
		else
		{
			cout << "No hay datos" << endl;
		}
	}

	//Funcion para elminar los datos
	void Delete_Lista()
	{
		delete Primer_Nodo;
	}
};