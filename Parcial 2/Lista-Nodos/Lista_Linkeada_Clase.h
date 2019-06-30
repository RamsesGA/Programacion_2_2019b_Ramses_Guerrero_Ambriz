#pragma once
#include "Librerias_Clases.h"

class Lista_Linkeada_Clase
{
public:
	//Miembros
	Nodo *n_Header;
	Nodo *n_Trailer;

	//Metodos
	Lista_Linkeada_Clase();
	//Funcion para conseguir el valor del frente
	int get_Front() const;
	//Funcion para connseguir el valor de atras
	int get_Back() const;
	//Funcion para añadir al nodo del frente
	void add_Front(int _dato);
	//Funcion para añadir al final de la lista
	void add_Back(int _dato);
	//Funcion para eliminar el valor del frente
	void remove_Front();
	//Funcion para eliminar el valor de atras
	void remove_Back();
	//Funcion para imprimir todos los numeros de final a inicio
	void print_Reverse();
	//Funcion para imprimir de inicio a fin
	void print_Forward();
	//Funcion para poder añadir un elemento X
	void add_X(int _input, int _dato);
	//Funcion para eleminar en X
	void remove_X(int _input);
	//Destructor
	~Lista_Linkeada_Clase();
	
};

