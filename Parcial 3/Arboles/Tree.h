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
	
		//Creaci�n de un nodo
		Node<T> *new_node(Node<T> _dato, Node<T> *_father);
	
		//Funci�n para poder insertar nodos
		void insert_node(Node<T> *&_tree, Node <T> *_dato, Node<T> *_father);
	
		//Tipos de recorrido
		void in_order(Node<T> *_tree);
		void pre_order(Node<T> *_tree);
		void post_order(Node<T> *_tree);
	
		//Chequeo del arbol equilibrado
		void check(Node<T> *_tree);
	
		//Funci�n para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node<T> *_tree, unsigned int _cont);
	
		//Funci�n para poder eliminar un nodo exacto
		void eliminate(Node<T> *_tree, Node<T> *_temp);
	
		//Funci�n para eliminar un nodo exacto
		void eliminate_node(Node<T> *_node);
	
		//Funci�n para poder encontrar el nodo profundo de la izq
		Node<T> *minimum(Node<T> *_node);
	
		//Funci�n para poder remplazar un nodo
		void replace(Node<T> *_node, Node<T> *_new_node);
	
		//Funci�n para destruir el nodo que deja la funci�n replace
		void destroy_node(Node<T> *_node);
	
		//Funci�n para rotar un �rbol binario
		void rotate_right(Node<T> * _tree);
		void rotate_left(Node<T> *_tree);
	
	
		Tree(Node <T> *_root);
		Tree();
		~Tree();
	
	
};

