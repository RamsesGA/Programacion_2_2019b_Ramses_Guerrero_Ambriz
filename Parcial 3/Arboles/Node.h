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

		//Constructor de un Nodo sin parámetros
		Node();
		//Constructor para obtener los datos en nodo
		Node(T _info);
		//Destructor
		~Node();

		//Función para poder añadir un nodo
		void insert_node(Node<T> *&_node);

		//Tipos de recorrido
		void in_order();
		void pre_order();
		void post_order();


		//Chequeo del arbol equilibrado
		void check();
		//Función para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node<T> *_tree, unsigned int _cont);


		//Función para poder eliminar un nodo exacto
		void eliminate(Node<T> *_info);
		//Función para eliminar un nodo exacto
		void eliminate_node(Node<T> *_node);
		//Función para poder encontrar el nodo profundo de la izq
		Node<T> *minimum(Node<T> *_node);
		//Función para poder remplazar un nodo
		void replace(Node<T> *_node, Node<T> *_new_node);
		//Función para destruir el nodo que deja la función replace
		void destroy_node(Node<T> *_node);


		bool operator > (Node<T> &_node);
		bool operator <(Node<T> &_node);

		friend istream & operator >> (istream & is, Node<T> & N);
};
