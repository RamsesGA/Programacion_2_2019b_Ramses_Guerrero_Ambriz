#include "Tree.h"

//--Nuevo nodo
Node * Tree::new_node(string _last, string _name, unsigned int _age, Node *_father)
{
	Node *node = new Node();

	//Almacenamos los datos
	node->last_name = _last;
	node->name = _name;
	node->age = _age;
	node->father = _father;

	//Indicamos lo que apuntará el nuevo pudiendo ser la raíz o las hojas
	node->p_left = nullptr;
	node->p_rigth = nullptr;

	return node;
}


//--Inserción
void Tree::insert_node(Node *& _tree, string _last, string _name, unsigned int _age, Node *_father)
{
	//En caso de ser un nodo vacio
	if (_tree == nullptr)
	{
		Node *n_node = new_node(_last, _name, _age, _father);
		//Guardamos el nuevo nodo
		_tree = n_node;
	}
	else
	{
		//To_do: sobrecarga
		string data = _tree->last_name;
		//Para ordenar los datos menores a la raíz a la izquierda
		if (_last < data)
		{
			insert_node(_tree->p_left, _last, _name, _age, _tree);
		}
		else
		{
			insert_node(_tree->p_rigth, _last, _name, _age, _tree);
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
		//Entramos a la función del peso
		node_weight(_tree, cont);
	}
	if (_tree->p_rigth != nullptr)
	{
		//Aumentamos el valor de cont
		cont++;
		Node *temp = new Node();
		//Entramos a la función del peso
		node_weight(_tree, cont);
	}
}

void Tree::node_weight(Node * _tree, unsigned int _cont)
{

	if (_tree->p_left != nullptr)
	{
		_cont++;
		node_weight(_tree->p_left, _cont);
		//Declaramos que la posición va a tener tal peso
		_tree->weight_left = _tree->p_left->all_weight;
		_tree->all_weight = ((_tree->level * _tree->weight_right) + (_tree->level * _tree->weight_left));
	}
	if (_tree->p_rigth != nullptr)
	{
		cont++;
		node_weight(_tree->p_rigth, _cont);
		//Declaramos que la posición de tal nodo va a tener tal peso
		_tree->weight_right = _tree->p_rigth->all_weight;
		_tree->all_weight = ((_tree->level * _tree->weight_left) + (_tree->level * _tree->weight_right));
	}
	else
	{
		_tree->all_weight = _tree->level + 1;
	}
	if (_tree->weight_left == _tree->weight_right)
	{
		cout << "El arbol esta balanceado" << endl;
	}
	else
	{
		cout << "El arbol, no esta balanceado" << endl;
	}
}


//Eliminación
void Tree::eliminate(Node *_tree, string _last)
{
	if (_tree == nullptr)
	{
		//No hace nada en caso de que el usuario no haya ingresado algo
		return;
	}
	else if (_last < _tree->last_name)
	{
		eliminate(_tree->p_left, _last);
	}
	else if (_last > _tree->last_name)
	{
		eliminate(_tree->p_rigth, _last);
	}
	//En caso de que ya encontró el valor, procedemos a eliminar
	else
	{
		eliminate_node(_tree);
	}
}

void Tree::eliminate_node(Node * _node)
{
	//Eliminamos un nodo, en caso de que sea par
	if (_node->p_left != nullptr && _node->p_rigth != nullptr)
	{
		Node *less = minimum(_node->p_rigth);

		_node->last_name = less->last_name;
		_node->name = less->name;
		_node->age = less->age;

		//matamos el nodo
		eliminate_node(less);
	}
	//Eliminamos un nodo en caso de que solo tenga un hijo
	else if (_node->p_left != nullptr)
	{
		replace(_node, _node->p_left);
		destroy_node(_node);
	}
	else if (_node->p_rigth != nullptr)
	{
		replace(_node, _node->p_rigth);
		destroy_node(_node);
	}
	//Eliminamos un nodo hoja
	else if (_node->p_left == nullptr && _node->p_rigth == nullptr)
	{
		replace(_node, nullptr);
		destroy_node(_node);
	}
}

Node * Tree::minimum(Node *_node)
{
	if (_node == nullptr)
	{
		//En caso de que no haya ingresado algo
		return nullptr;
	}
	if (_node->p_left)
	{
		//Recorremos a la izq en busca del último nodo de la izq
		return minimum(_node->p_left);
	}
	//En caso de que no tenga un lado izq, regresamos el nodo
	else
	{
		return _node;
	}

}

void Tree::replace(Node *_node, Node * _new_node)
{
	//Para saber si el nodo que se envió tiene padre
	if (_node->father)
	{
		//Dentro al padre modifica su puntero al dato que se va a cambiar
		if (_node->last_name == _node->father->p_left->last_name)
		{
			_node->father->p_left = _new_node;
		}
		else if (_node->last_name == _node->father->p_rigth->last_name)
		{
			_node->father->p_rigth = _new_node;
		}
	}
	if (_new_node)
	{
		//Se le asigna el nuevo padre
		_new_node->father = _node->father;
	}
}

void Tree::destroy_node(Node * _node)
{
	_node->p_left = nullptr;
	_node->p_rigth = nullptr;
	delete _node;
}


//--Inicializador
Tree::Tree() {}
//--Destructor
Tree::~Tree() {}
