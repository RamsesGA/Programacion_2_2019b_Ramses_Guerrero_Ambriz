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
	void Add_Cola(int _num);
	//Funcion para mandar a llamar a la funcion imprimir del nodo
	void Imprimir_Cola_Nodo();
	//Funcion para eliminar los datos
	void Delete_Cola();
};

