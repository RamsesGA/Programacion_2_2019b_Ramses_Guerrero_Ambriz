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
	void Add_Pila(int _num);
	//Funcion para mandar a llamar a la funcion imprimir del nodo
	void Imprimir_Pila_Nodo();
	//Funcion para eliminar los datos
	void Delete_Pila();
};
