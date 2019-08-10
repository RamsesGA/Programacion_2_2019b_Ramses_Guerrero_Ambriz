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
	
		//Funci�n para ingresar nodos al �rbol
		int Push(Nodes<T>*);

		//Funciones de impresi�n
		void Inorden();
		void Preorden();
		void Postorden();

		//
		void Balance();

		//Funci�n para eliminar nodos del �rbol
		void Pull(Nodes<T>*);

		//Funci�n para poder rotar
		void Rotacion();
	
};

