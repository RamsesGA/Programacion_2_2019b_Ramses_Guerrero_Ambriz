#pragma once
#include <string> 
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class Nodos
{
	public:
	
		//Mienbros
		T Dato;
	
		Nodos<T> *Derecha;
		Nodos<T> *Izquierda;
		Nodos<T> *Ant = nullptr;
	
		int Nivel = 0;
		int balIzq = 0;
		int balDer = 0;
		int pesoAct = 0;
	
		//Metodos
		void pre_orden_izq();
		void pre_orden_dere();
		void in_orden();
		void pre_orden();
		void post_orden();
		void balance(int);
		void rotacion();
	
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
};

