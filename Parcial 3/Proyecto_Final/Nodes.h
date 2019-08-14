#pragma once
#include <string> 
#include <iostream>

template<class T>
class Arbol_AVL;
template<class T>
class Arbol_Bin;

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class Nodos
{
	protected:
		//Miembros
		T Dato;

		Nodos<T> *Derecha;
		Nodos<T> *Izquierda;
		Nodos<T> *Ant = nullptr;

		int Nivel = 0;
		int contador = 0;

	public:
		//Metodos
		T get();

		void in_orden();
		void pre_orden();
		void post_orden();
		void rotacion();

		int balanceado(int);
		int ingresar(Nodos<T>*, Nodos<T>*);
		int eliminar(Nodos<T>*, Nodos<T>*);
	
		//Sobrecarga de operadores 
		bool operator < (Nodos<T>&);
		bool operator > (Nodos<T>&);
		bool operator == (Nodos<T>&);
		
		Nodos desplazar(Nodos<T>*);
	
		//Constructores
		Nodos(T);
		Nodos();
	
		//Destructor
		~Nodos();

		friend class Arbol_AVL<T>;
		friend class Arbol_Bin<T>;
};

