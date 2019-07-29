#include "Tree.h"

//--Nuevo nodo
Node * Tree::new_node(string _last, string _name, unsigned int _age)
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


//--Inserción
void Tree::insert_node(Node *& _tree, string _last, string _name, unsigned int _age)
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
		string data = _tree->last_name;
		//Para ordenar los datos menores a la raíz a la izquierda
		if (_last < data)
		{
			insert_node(_tree->p_left, _last, _name, _age);
		}
		else
		{
			insert_node(_tree->p_rigth, _last, _name, _age);
		}
	}
}


//--Impresion
void Tree::in_order(Node * _tree)
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

void Tree::pre_order(Node * _tree)
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

void Tree::post_order(Node * _tree)
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


//---Chequeo 
void Tree::check(Node * _tree)
{
	//Primero checamos si el nodo a la izq no es la hoja
	if (_tree->p_left != nullptr)
	{
		Node *temp = new Node();
		//Entramos a la función del peso
		node_weight(_tree, cont, temp);
	}
	if (_tree->p_rigth != nullptr)
	{
		//Aumentamos el valor de cont
		cont++;
		Node *temp = new Node();
		//Entramos a la función del peso
		node_weight(_tree, cont, temp);
	}
}

void Tree::node_weight(Node * _tree, unsigned int _cont, Node * _temp)
{
	_temp = _tree;
	_temp->level = _cont;

	if (_temp->p_left != nullptr)
	{
		_cont++;
		node_weight(_tree->p_left, _cont, _temp);
		//Declaramos que la posición va a tener tal peso
		_tree->weight_left = _tree->p_left->all_weight;
		_tree->all_weight = ((_tree->level * _tree->weight_right) + (_tree->level * _tree->weight_left));
	}
	if (_temp->p_rigth != nullptr)
	{
		cont++;
		node_weight(_tree->p_rigth, _cont, _temp);
		//Declaramos que la posición de tal nodo va a tener tal peso
		_tree->weight_right = _tree->p_rigth->all_weight;
		_tree->all_weight = ((_tree->level * _tree->weight_left) + (_tree->level * _tree->weight_right));
	}
	else
	{
		_temp->all_weight = _temp->level + 1;
	}
}


//--Inicializador
Tree::Tree() {}

//--Destructor
Tree::~Tree() {}
