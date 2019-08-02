#pragma once
#include "Libraries.h"

class Node
{
	public:
		//--Miembros
		Node *p_left;
		Node *p_rigth;
		Node *father;
	
		string last_name;
		string name;
		unsigned int age;
	
		unsigned int level = 0;
		unsigned int weight_left = 0;
		unsigned int weight_right = 0;
		unsigned int all_weight = 0;
	
		//--Metodos
	
		//-Sobrecargas de operadores
	
		//Output
		friend ostream & operator << (ostream & _out, Node *_tree);
		//Input
		friend istream & operator >> (istream &_in, Node *_node);
	
		//Comparación
		bool operator < (Node &_node);
		bool operator > (Node &_node);
	
			Node();
			~Node();
};

