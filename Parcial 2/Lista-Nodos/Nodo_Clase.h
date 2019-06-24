#pragma once
#include "Librerias_Clases.h"

using namespace std;

class Nodo
{
public:
	//Miembros o atributos
	Nodo *Nodo_Siguiente;
	Nodo *Nodo_Anterior;
	int Numero;

	//Metodos
	Nodo() {};

	//Funcion para crear un nodo nuevo
	Nodo(int _Num)
	{
		Numero = _Num;
		Nodo_Siguiente = nullptr;
		Nodo_Anterior = nullptr;
	}

	//Funcion para agregar el dato
	void Add_Nodo(Nodo *_Nuevo_Nodo)
	{
		if (Nodo_Siguiente != nullptr)
		{
			Nodo_Siguiente->Add_Nodo(_Nuevo_Nodo);
		}
		else
		{
			Nodo_Siguiente = _Nuevo_Nodo;
		}
	}

	//Funcion para imprimir los datos
	void Imprimir_Nodo()
	{
		cout << "Los numeros son: " << Numero <<endl;
		if (Nodo_Siguiente != nullptr)
		{
			Nodo_Siguiente->Imprimir_Nodo();
		}
	}

	//Funcion para el destructor
	~Nodo()
	{
		if (Nodo_Siguiente != nullptr)
		{
			delete Nodo_Siguiente;
		}
	}
};