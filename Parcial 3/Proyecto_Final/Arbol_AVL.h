#pragma once
#include "Nodes.h"
#include <string> 
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class Arbol_AVL
{
	public:
		//Mienbros
		Nodes<T>*Raiz = nullptr;
		int Cont = 0;
	
	
		//Metodos
		Arbol_AVL();
		Arbol_AVL(Nodes<T>*);

		//Destructor
		~Arbol_AVL();
	
		//Función para ingresar nodos al árbol
		int Push(Nodes<T>*);

		//Funciones de impresión
		void Inorden();
		void Preorden();
		void Postorden();

		//
		void Balance();

		//Función para eliminar nodos del árbol
		void Pull(Nodes<T>*);

		//Función para poder rotar
		void Rotacion();
	
};

