#pragma once
#include "Clases_Librerias.h"

using namespace std;

class Nodo
{
public:
	//atributos o miembros
	Nodo *SiguienteNodo;
	int _Numero;

	//Metodos
	Nodo() {};
	//Para crear un nodo
	Nodo(int _num)
	{
		_Numero = _num;
		SiguienteNodo = nullptr;
	}
	//Funcion para agregar
	void Add_Nodo(Nodo *_Nuevo_Nodo)
	{
		if (SiguienteNodo != nullptr)
		{
			SiguienteNodo->Add_Nodo(_Nuevo_Nodo);
		}
		else
		{
			SiguienteNodo = _Nuevo_Nodo;
		}
	}
	//Funcion para imprimir los datos
	void Imprimir_Nodo()
	{
		cout << "El numero es: " << _Numero << endl;
		if (SiguienteNodo != nullptr)
		{
			SiguienteNodo->Imprimir_Nodo();
		}
	}
	//Funcion para el destructor
	~Nodo()
	{
		if (SiguienteNodo != nullptr)
		{
			delete SiguienteNodo;
		}
	}
}; 
