#pragma once
#include "Librerias_Clases.h"

using namespace std;

class Nodo
{
public:
	//Miembros o atributos
	Nodo *p_Prev;
	Nodo *p_Next;
	int Dato;

	//Metodos
	Nodo() {};
};