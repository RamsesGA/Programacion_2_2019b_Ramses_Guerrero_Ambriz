#pragma once
#include "Nodes.h"
#include "Arboles.h"
#include <string> 
#include <iostream>

template<class T>
class Arbol_Bin : Arboles<T>
{
	protected:
		//Miembros
		Nodos<T>*Raiz = nullptr;

	public:
		//Metodos

		Arbol_Bin(Nodos<T>*);
		Arbol_Bin();

		//Destructor
		~Arbol_Bin();
	
		//Función para ingresar nodos al árbol
		int ingresar(Nodos<T>*&);
	
		//Función para eliminar nodos del árbol
		void eliminar(Nodos<T>*);
	
		//Funciones de impresión
		void in_orden();
		void pre_orden();
		void post_orden();
};

