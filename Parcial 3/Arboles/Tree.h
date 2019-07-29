#pragma once
#include "Node.h"
#include "Libraries.h"

class Tree
{
	public:
		//---Miembros 

		unsigned int cont = 0;

		//---Metodos

		//Creación de un nodo
		Node *new_node(string _last, string _name, unsigned int _age);
		//Función para poder insertar nodos
		void insert_node(Node *&_tree, string _last, string _name, unsigned int _age);
		//Tipos de recorrido
		void in_order(Node *_tree);
		void pre_order(Node *_tree);
		void post_order(Node *_tree);
		//Chequeo del arbol equilibrado
		void check(Node *_tree);
		//Función para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node *_tree, unsigned int _cont, Node *_temp);

		Tree();
		~Tree();


};

