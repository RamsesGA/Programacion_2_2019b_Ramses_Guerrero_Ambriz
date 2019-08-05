#include "Tree.h"

//--Nuevo nodo
template <class T>
Node<T> * Tree<T>::new_node(Node<T> _dato, Node<T> *_father)
{
	Node<T> *node = new Node<T>();

	//Almacenamos los datos
	node->Personas = _dato.Personas;

	node->father = _father;

	//Indicamos lo que apuntará el nuevo pudiendo ser la raíz o las hojas
	node->p_left = nullptr;
	node->p_rigth = nullptr;

	return node;
}


//--Inserción
template <class T>
void Tree<T>::insert_node(Node<T> *& _tree,Node<T> *_dato, Node<T> *_father)
{
	//En caso de ser un nodo vacio
	if (_tree == nullptr)
	{
		Node<T> *n_node = new_node(_dato, _father);
		//Guardamos el nuevo nodo
		_tree = n_node;
	}
	else
	{
		Node<T> *temp = new Node<T>();
		temp->Personas = _dato->Personas;

		//Para ordenar los datos menores a la raíz a la izquierda
		if (*temp < *_tree)
		{
			insert_node(_tree->p_left, _dato, _tree);
		}
		else
		{
			insert_node(_tree->p_rigth, _dato, _tree);
		}
	}
}


//--Impresion
template <class T>
void Tree<T>::in_order(Node<T> * _tree)
{
	if (_tree == nullptr)
	{
		return;
	}
	else
	{
		//Usamos recursividad para recorrer primero el lado izq
		if (_tree->p_left != nullptr)
		{
			in_order(_tree->p_left);
		}
		//Imprimimos los datos
		cout << _tree << endl;
		//Finalmente pasamos al lado derecho
		if (_tree->p_rigth != nullptr)
		{
			in_order(_tree->p_rigth);
		}
	}
}

template <class T>
void Tree<T>::pre_order(Node<T> * _tree)
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
		if (_tree->p_left != nullptr)
		{
			pre_order(_tree->p_left);
		}		
		//Finalmente pasamos al lado derecho
		if (_tree->p_rigth != nullptr)
		{
			pre_order(_tree->p_rigth);
		}
	}
}

template <class T>
void Tree<T>::post_order(Node<T> * _tree)
{
	if (_tree == nullptr)
	{
		return;
	}
	else
	{
		//Usamos recursividad para recorrer primero el lado izq
		if (_tree->p_left != nullptr)
		{
			post_order(_tree->p_left);
		}
		//Finalmente pasamos al lado derecho
		if (_tree->p_rigth != nullptr)
		{
			post_order(_tree->p_rigth);
		}
		//Imprimimos los datos
		cout << _tree << endl;
	}
}


//---Chequeo 
template <class T>
void Tree<T>::check(Node<T> * _tree)
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
		Node<T> *temp = new Node<T>();
		//Entramos a la función del peso
		node_weight(_tree, cont);
	}
}

template <class T>
void Tree<T>::node_weight(Node<T> * _tree, unsigned int _cont)
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
template <class T>
void Tree<T>::eliminate(Node<T> *_tree, Node<T> *_temp)
{
	if (_tree == nullptr)
	{
		//No hace nada en caso de que el usuario no haya ingresado algo
		return;
	}
	else if (*_temp < *_tree)
	{
		eliminate(_tree->p_left, _temp);
	}
	else if (*_temp > *_tree)
	{
		eliminate(_tree->p_rigth, _temp);
	}
	//En caso de que ya encontró el valor, procedemos a eliminar
	else
	{
		eliminate_node(_tree);
	}
}

template <class T>
void Tree<T>::eliminate_node(Node<T> * _node)
{
	//Eliminamos un nodo, en caso de que sea par
	if (_node->p_left != nullptr && _node->p_rigth != nullptr)
	{
		Node<T> *less = minimum(_node->p_rigth);

		//CUIDADO
		_node->Personas = less->Personas;

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

template <class T>
Node<T> * Tree<T>::minimum(Node<T> *_node)
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

template <class T>
void Tree<T>::replace(Node<T> *_node, Node<T> * _new_node)
{
	//Para saber si el nodo que se envió tiene padre
	if (_node->father)
	{
		//Dentro al padre modifica su puntero al dato que se va a cambiar

		//Condición en caso de que sea un nodo par
		if (_node->father->p_left != nullptr && _node->father->p_rigth != nullptr)
		{
			if (_node->last_name == _node->father->p_left->last_name && _node->name == _node->father->p_left->name && _node->age == _node->father->p_left->age)
			{
				_node->father->p_left = _new_node;
			}
			else if (_node->last_name == _node->father->p_rigth->last_name && _node->name == _node->father->p_rigth->name && _node->age == _node->father->p_rigth->age)
			{
				_node->father->p_rigth = _new_node;
			}
			else
			{
				cout << "Ingreso un dato incorrecto" << endl;
			}
		}
		//Un nodo impar a la izq
		else if (_node->father->p_left != nullptr && _node->father->p_rigth == nullptr)
		{
			if (_node->last_name == _node->father->p_left->last_name && _node->name == _node->father->p_left->name && _node->age == _node->father->p_left->age)
			{
				_node->father->p_left = _new_node;
			}
			else
			{
				cout << "Ingreso un dato incorrecto" << endl;
			}
		}
		//Un nodo impar a la dere
		else if (_node->father->p_left == nullptr && _node->father->p_rigth != nullptr)
		{
			if (_node->last_name == _node->father->p_rigth->last_name && _node->name == _node->father->p_rigth->name && _node->age == _node->father->p_rigth->age)
			{
				_node->father->p_rigth = _new_node;
			}
			else
			{
				cout << "Ingreso un dato incorrecto" << endl;
			}
		}
	}
	if (_new_node)
	{
		//Se le asigna el nuevo padre
		_new_node->father = _node->father;
	}
}

template <class T>
void Tree<T>::destroy_node(Node<T> * _node)
{
	_node->p_left = nullptr;
	_node->p_rigth = nullptr;
	delete _node;
}

template <class T>
void Tree<T>::rotate_right(Node<T> * _tree)
{
	Node<T> *temp = new Node<T>();
	temp = _tree->p_left;

	//Re apuntamos todo
	temp->p_rigth->father = temp->father;
	temp->father = _tree->father;
	_tree->father = _tree->p_left;
	_tree->p_left = _tree->father->p_rigth;
	temp->p_rigth = temp->p_rigth->father;
}

template <class T>
void Tree<T>::rotate_left(Node<T> * _tree)
{
	Node<T> *temp = new Node<T>();
	temp = _tree->p_rigth;

	//Re apuntamos todo
	temp->p_left->father = temp->father;
	temp->father = _tree->father;
	_tree->father = _tree->p_rigth;
	_tree->p_rigth = _tree->father->p_left;
	temp->p_left = temp->p_left->father;
}

template<class T>
Tree<T>::Tree(Node<T>* _root)
{
	root = _root;
}

//--Inicializador
template <class T>
Tree<T>::Tree() {}
//--Destructor
template <class T>
Tree<T>::~Tree() {}

//Importante
template class Node <Person>;