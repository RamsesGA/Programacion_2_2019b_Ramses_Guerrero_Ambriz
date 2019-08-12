#pragma once
#include "Nodes.h"
#include <string> 
#include <iostream>

template<class T>
class Arbol_Bin
{
	public:
	
		//Miembros
		Nodos<T>*Raiz = nullptr;
	

		//Metodos

		Arbol_Bin(Nodos<T>*);
		Arbol_Bin();

		//Destructor
		~Arbol_Bin();
	
		//Funci�n para ingresar nodos al �rbol
		int ingresar(Nodos<T>*);
	
		//Funci�n para eliminar nodos del �rbol
		void eliminar(Nodos<T>*);
	
		//Funciones de impresi�n
		void in_orden();
		void pre_orden();
		void post_orden();
};

