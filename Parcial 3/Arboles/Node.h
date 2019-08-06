#pragma once
#include "Person.h"

template <class T>
class Node
{
	public:
		//--Miembros
		Node<T> *p_left;
		Node<T> *p_rigth;
		Node<T> *father = nullptr;

		//Tipo de dato del template
		T Dato;

		//Tipo de multidato
	
		unsigned int level = 0;
		unsigned int weight_left = 0;
		unsigned int weight_right = 0;
		unsigned int all_weight = 0;
		unsigned int cont = 0;

		//--Metodos

		//Constructor de un Nodo sin par�metros
		Node();
		//Constructor para obtener los datos en nodo
		Node(T _info);
		//Destructor
		~Node();

		//Funci�n para poder a�adir un nodo
		void insert_node(Node<T> *&_node);

		//Tipos de recorrido
		void in_order();
		void pre_order();
		void post_order();


		//Chequeo del arbol equilibrado
		void check();
		//Funci�n para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node<T> *_tree, unsigned int _cont);


		//Funci�n para poder eliminar un nodo exacto
		void eliminate(Node<T> *_info);
		//Funci�n para eliminar un nodo exacto
		void eliminate_node(Node<T> *_node);
		//Funci�n para poder encontrar el nodo profundo de la izq
		Node<T> *minimum(Node<T> *_node);
		//Funci�n para poder remplazar un nodo
		void replace(Node<T> *_node, Node<T> *_new_node);
		//Funci�n para destruir el nodo que deja la funci�n replace
		void destroy_node(Node<T> *_node);


		bool operator > (Node<T> &_node);
		bool operator <(Node<T> &_node);

		friend istream & operator >> (istream & is, Node<T> & N);
};
