#pragma once
#include "Node.h"

template <class T>
class Tree
{
	public:
		//---Miembros 
	
		unsigned int cont = 0;
		Node <T> *root;
	
	
		//---Metodos
	
		//Creación de un nodo
		Node<T> *new_node(Node<T> _dato, Node<T> *_father);
	
		//Función para poder insertar nodos
		void insert_node(Node<T> *&_tree, Node <T> *_dato, Node<T> *_father);
	
		//Tipos de recorrido
		void in_order(Node<T> *_tree);
		void pre_order(Node<T> *_tree);
		void post_order(Node<T> *_tree);
	
		//Chequeo del arbol equilibrado
		void check(Node<T> *_tree);
	
		//Función para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node<T> *_tree, unsigned int _cont);
	
		//Función para poder eliminar un nodo exacto
		void eliminate(Node<T> *_tree, Node<T> *_temp);
	
		//Función para eliminar un nodo exacto
		void eliminate_node(Node<T> *_node);
	
		//Función para poder encontrar el nodo profundo de la izq
		Node<T> *minimum(Node<T> *_node);
	
		//Función para poder remplazar un nodo
		void replace(Node<T> *_node, Node<T> *_new_node);
	
		//Función para destruir el nodo que deja la función replace
		void destroy_node(Node<T> *_node);
	
		//Función para rotar un árbol binario
		void rotate_right(Node<T> * _tree);
		void rotate_left(Node<T> *_tree);
	
	
		Tree(Node <T> *_root);
		Tree();
		~Tree();
	
	
};

