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

		//Funci�n para poder insertar nodos
		void insert(Node<T> *&_node);
		void insert(T _dato);


		//Tipos de impresion
		void in_order_tree();
		void pre_order_tree();
		void post_order_tree();

		//Chequeo
		void check_tree();
	

		//Eliminaci�n
		void eliminate_in_tree(Node<T> *_info);

		//Funci�n para rotar un �rbol binario
		void rotate_right(Node<T> *&_node);
		void rotate_left(Node<T> *&_node);
	
	
		Tree(Node <T> *_root);
		Tree();
		~Tree();
	
	
};

