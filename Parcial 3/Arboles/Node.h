#pragma once
#include "Person.h"

template <class T>
class Node
{
	public:
		//--Miembros
		Node<T> *p_left;
		Node<T> *p_rigth;
		Node<T> *father;

		T Personas;

		//Tipo de multidato
	
		unsigned int level = 0;
		unsigned int weight_left = 0;
		unsigned int weight_right = 0;
		unsigned int all_weight = 0;


	
		//--Metodos
		friend istream & operator >> (istream & is, Node<T> & N);


		Node(T _info);
		Node();
		~Node();


};
