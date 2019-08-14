#pragma once
#include "Nodes.h"

template<class T>
class Arboles
{
	public:
		//Metodos para AVL y BIN
		virtual int ingresar(Nodos<T>*&) = 0;
		virtual void eliminar(Nodos<T>*) = 0;
		virtual void in_orden() = 0;
		virtual void post_orden() = 0;
		virtual void pre_orden() = 0;

		//Constructor
		Arboles();
		//Destructor
		~Arboles();
};

