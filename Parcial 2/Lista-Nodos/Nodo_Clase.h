#pragma once
#include "Librerias_Clases.h"

using namespace std;

class Nodo
{
public:
	//Atributos - miembros
	int Datos;
	Nodo *Puntero_Anterior;
	Nodo* Puntero_Siguiente;
	//Metodos - constructores
	Nodo() {};

	//Para crear el nodo
	Nodo *Crear_Nodo(Nodo *Info, int _dato)
	{
		Nodo *Nuevo_Nodo = new Nodo();
		Nuevo_Nodo->Datos = _dato;
		Nuevo_Nodo->Puntero_Siguiente = nullptr;
		Nuevo_Nodo->Puntero_Anterior = nullptr;
		Info = Nuevo_Nodo;
		return Info;
	}

	void Imprimir_Datos(Nodo *Info)
	{
		Nodo *Temporal = Info;
		cout << "-----Impresion izquierda a derecha-----" << endl;
		while (Temporal != nullptr)
		{
			cout << "Los numeros son :" << Temporal->Datos << endl;	
			Temporal = Temporal->Puntero_Siguiente;
		}
		//Temporal = Info;
		cout << "Impresion derecha a izquierda" << endl;
		while (Temporal != nullptr)
		{
			cout << "Los numeros son :" << Temporal->Datos << endl;
			Temporal = Temporal->Puntero_Anterior;
		}
	}
};