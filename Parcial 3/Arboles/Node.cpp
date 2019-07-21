#include "Node.h"

Node * Node::new_node(string _last, string _name, unsigned int _age)
{
	Node *node = new Node();

	//Almacenamos los datos
	node->last_name = _last;
	node->name = _name;
	node->age = _age;

	//Indicamos lo que apuntará el nuevo pudiendo ser la raíz o las hojas
	node->p_left = nullptr;
	node->p_rigth = nullptr;

	return node;
}

void Node::insert_node(Node *& _tree, string _last, string _name, unsigned int _age)
{
	//En caso de ser un nodo vacio
	if (_tree == nullptr)
	{
		Node *n_node = new_node(_last, _name, _age);
		//Guardamos el nuevo nodo
		_tree = n_node;
	}
	else
	{
		unsigned int data = _tree->age;
		//Para ordenar los datos menores a la raíz a la izquierda
		if (_age < data)
		{
			insert_node(_tree->p_left, _last, _name, _age);
		}
		else
		{
			insert_node(_tree->p_rigth, _last, _name, _age);
		}
	}
}

void Node::in_order(Node * _tree)
{
	if (_tree == nullptr)
	{
		return;
	}
	else
	{
		//Usamos recursividad para recorrer primero el lado izq
		in_order(_tree->p_left);
		//Imprimimos los datos
		cout << _tree << endl;
		//Finalmente pasamos al lado derecho
		in_order(_tree->p_rigth);
	}
}

void Node::pre_order(Node * _tree)
{
	if (_tree == nullptr)
	{
		return;
	}
	else
	{
		//Imprimimos los datos
		cout << _tree << endl;
		//Usamos recursividad para recorrer primero el lado izq
		pre_order(_tree->p_left);
		//Finalmente pasamos al lado derecho
		pre_order(_tree->p_rigth);
	}
}

void Node::post_order(Node * _tree)
{
	if (_tree == nullptr)
	{
		return;
	}
	else
	{
		//Usamos recursividad para recorrer primero el lado izq
		post_order(_tree->p_left);
		//Finalmente pasamos al lado derecho
		post_order(_tree->p_rigth);
		//Imprimimos los datos
		cout << _tree << endl;
	}
}

ostream & operator<<(ostream & _out, Node * _tree)
{
	_out << "\nEl apellido es - - > " << _tree->last_name << "\nEl nombre es - - > " << _tree->name << "\nY la edad es - - > " << _tree->age << endl;
	return _out;
}

Node::Node() {}
Node::~Node() {}