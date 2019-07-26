#pragma once
#include "Libraries.h"

class Node
{
	public:
		//Miembros
		Node *p_left;
		Node *p_rigth;

		string last_name;
		string name;
		unsigned int age;

		//Metodos

		//Sobrecarga
		friend ostream & operator << (ostream & _out, Node *_tree);


		Node();
		~Node();
};

