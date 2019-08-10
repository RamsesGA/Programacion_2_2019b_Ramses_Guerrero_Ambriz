#pragma once
#include <string> 
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<class T>
class Nodes
{
	public:
	
		//Mienbros
		T Dato;
	
		Nodes<T> *Rigth;
		Nodes<T> *Left;
		Nodes<T> *Ant = nullptr;
	
		int Nivel = 0;
		int balIzq = 0;
		int balDer = 0;
		int pesoAct = 0;
	
		//Metodos
		void PreordenLeft();
		void PreordenRigth();
		void Inorden();
		void Postorden();
		void Balance(int);
		void Rotacion();
	
		int Push(Nodes<T>*, Nodes<T>*);
		int Pull(Nodes<T>*, Nodes<T>*);
	
		//Sobrecarga de operadores 
		bool operator < (Nodes<T>&);
		bool operator > (Nodes<T>&);
		bool operator == (Nodes<T>&);
	
	
		Nodes Desplazar(Nodes<T>*);
	
		//Constructores
		Nodes(T);
		Nodes();
	
		//Destructor
		~Nodes();
};

