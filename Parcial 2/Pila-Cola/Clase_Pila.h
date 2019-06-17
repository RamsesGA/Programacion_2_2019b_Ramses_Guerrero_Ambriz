#pragma once
#include "Clases_Librerias.h"

using namespace std;

class Pila
{
public:
	//Atributos o miembros
	Nodo *PrimerNodo = nullptr;
	//Metodos
	Pila() {};
	
	//Funcion para crear un nodo y agregar datos
	void Add_Pila(int _num)
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
	void Imprimir_Pila_Nodo()
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
	void Delete_Pila()
	{
		delete PrimerNodo;
	}
};
