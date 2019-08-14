#pragma once
#include <string> 
#include <iostream>
#include "Arboles.h"
#include "Nodes.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class Arbol_AVL : Arboles<T>
{
	protected:
		//Miembros
		Nodos<T>*Raiz = nullptr;
		int Cont = 0;

	public:
		//Metodos
		Arbol_AVL();
		Arbol_AVL(Nodos<T>*);

		//Destructor
		~Arbol_AVL();
	
		//Función para ingresar nodos al árbol
		int ingresar(Nodos<T>*&);

		//Funciones de impresión
		void in_orden();
		void pre_orden();
		void post_orden();

		//void balanceado();
		void balancear();

		//Función para eliminar nodos del árbol
		void eliminar(Nodos<T>*);

		//Función para poder rotar
		void rotacion();
};

