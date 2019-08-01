#pragma once
#include "Node.h"
#include "Libraries.h"

class Tree
{
	public:
		//---Miembros 

		unsigned int cont = 0;

		//---Metodos

		//Creaci�n de un nodo
		Node *new_node(string _last, string _name, unsigned int _age, Node *_father);
		//Funci�n para poder insertar nodos
		void insert_node(Node *&_tree, string _last, string _name, unsigned int _age, Node *_father);
		//Tipos de recorrido
		void in_order(Node *_tree);
		void pre_order(Node *_tree);
		void post_order(Node *_tree);
		//Chequeo del arbol equilibrado
		void check(Node *_tree);
		//Funci�n para poder asignar un peso a los nodos, incluso a la hoja
		void node_weight(Node *_tree, unsigned int _cont);
		//Funci�n para poder eliminar un nodo exacto
		void eliminate(Node *_tree, string _last);
		//Funci�n para eliminar un nodo exacto
		void eliminate_node(Node *_node);
		//Funci�n para poder encontrar el nodo profundo de la izq
		Node *minimum(Node *_node);
		//Funci�n para poder remplazar un nodo
		void replace(Node *_node, Node *_new_node);
		//Funci�n para destruir el nodo que deja la funci�n replace
		void destroy_node(Node *_node);

		Tree();
		~Tree();


};

