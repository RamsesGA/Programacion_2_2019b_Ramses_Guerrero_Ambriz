#include "Node.h"

//Constructor de un Nodo sin parámetros
template<class T>
Node<T>::Node()
{
	p_left = nullptr;
	p_rigth = nullptr;
}


//Constructor para obtener los datos en nodo
template<class T>
Node<T>::Node(T _info) : Dato(_info){}


//Destructor
template<class T>
inline Node<T>::~Node()
{
	//Checamos si el lado izquierdo aún tiene datos
	if (p_left != nullptr)
	{
		delete p_left;
	}
	//Checamos si el lado derecho aún tiene datos
	if (p_rigth != nullptr)
	{
		delete p_rigth;
	}
}


//Función que viene cargando el dato desde INSERT de tree.cpp
template<class T>
void Node<T>::insert_node(Node<T> *& _node)
{
	//Checamos si el nodo que se ingresó, es menor al que ya existe
	if (*this > *_node)
	{
		//Checamos si el nodo existente tiene algo a la derecha
		if (p_left != nullptr)
		{
			//Si ese lado existe, entramos al nodo que ocupa el espacio y comparamos de nuevo
			p_left->insert_node(_node);
		}
		//En caso que si este vacio
		else
		{
			//Ingresamos el nodo
			p_left = _node;
		}
	}
	//En caso que el nodo ingresado sea mayor al nodo que ya existe
	else
	{
		//Checamos si el nodo existente tiene algo a la izquierda
		if (p_rigth != nullptr)
		{
			//Si su lado izquierdo está ocupado, entramos al nodo y volvemos a comparar
			p_rigth->insert_node(_node);
		}
		//En caso que si este vacio
		else
		{
			//Ingresamos el nodo
			p_rigth = _node;
		}
	}
}


//Impresion 1
template<class T>
void Node<T>::in_order()
{
	//Usamos recursividad para recorrer primero el lado izq
	if (p_left != nullptr)
	{
		p_left->in_order();
	}
	//Imprimimos los datos
	cout << Dato << endl;
	//Finalmente pasamos al lado derecho
	if (p_rigth != nullptr)
	{
		p_rigth->in_order();
	}
}


//Impresion 2
template<class T>
void Node<T>::pre_order()
{
	//Imprimimos los datos
	cout << Dato << endl;
	//Usamos recursividad para recorrer primero el lado izq
	if (p_left != nullptr)
	{
		p_left->pre_order();
	}
	//Finalmente pasamos al lado derecho
	if (p_rigth != nullptr)
	{
		p_rigth->pre_order();
	}
}


//Impresion 3
template<class T>
void Node<T>::post_order()
{
	//Usamos recursividad para recorrer primero el lado izq
	if (p_left != nullptr)
	{
		p_left->post_order();
	}
	//Finalmente pasamos al lado derecho
	if (p_rigth != nullptr)
	{
		p_rigth->post_order();
	}
	//Imprimimos los datos
	cout << Dato << endl;
}


//---Chequeo 
template<class T>
void Node<T>::check()
{
	//Primero checamos si el nodo a la izq no es la hoja
	if (p_left != nullptr)
	{
		//Entramos a la función del peso
		node_weight(this, cont);
	}
	if (p_rigth != nullptr)
	{
		//Aumentamos el valor de cont
		cont++;
		Node<T> *temp;
		//Entramos a la función del peso
		node_weight(this, cont);
	}
}
template<class T>
void Node<T>::node_weight(Node<T>* _tree, unsigned int _cont)
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
template<class T>
void Node<T>::eliminate(Node<T>* _info)
{
	if (*_info < *this)
	{
		p_left->eliminate(_info);
	}
	else if (*_info > *this)
	{
		p_rigth->eliminate(_info);
	}
	//En caso de que ya encontró el valor, procedemos a eliminar
	else
	{
		this->eliminate_node(_info);
	}
}
template<class T>
void Node<T>::eliminate_node(Node<T>* _node)
{
	//Eliminamos un nodo, en caso de que sea par
	if (_node->p_left != nullptr && _node->p_rigth != nullptr)
	{
		Node<T> *less = minimum(_node->p_rigth);

		//CUIDADO
		_node->Dato = less->Dato;

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
template<class T>
Node<T>* Node<T>::minimum(Node<T>* _node)
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
template<class T>
void Node<T>::replace(Node<T>* _node, Node<T>* _new_node)
{
	//Para saber si el nodo que se envió tiene padre
	if (_node->father)
	{
		//Dentro al padre modifica su puntero al dato que se va a cambiar

		//Condición en caso de que sea un nodo par
		if (_node->father->p_left != nullptr && _node->father->p_rigth != nullptr)
		{
			if (_node == _node->father->p_left && _node == _node->father->p_left && _node == _node->father->p_left)
			{
				_node->father->p_left = _new_node;
			}
			else if (_node == _node->father->p_rigth && _node == _node->father->p_rigth && _node == _node->father->p_rigth)
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
			if (_node == _node->father->p_left && _node == _node->father->p_left && _node == _node->father->p_left)
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
			if (_node == _node->father->p_rigth && _node == _node->father->p_rigth && _node == _node->father->p_rigth)
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
template<class T>
void Node<T>::destroy_node(Node<T>* _node)
{
	_node->p_left = nullptr;
	_node->p_rigth = nullptr;
	delete _node;
}


//Sobrecarga del operador < para la Persona.h
template<class T>
bool Node<T>::operator>(Node &_nodo)
{
	return Dato > _nodo.Dato;
}
template<class T>
bool Node<T>::operator<(Node<T>& _node)
{
	return Dato < _node.Dato;
}






//Importante
template class Node <Person>;

//Sobrecarga del operador input
istream & operator>>(istream & _in, Node<Person>& _node)
{
	_in >> _node.Dato;
	return _in;
}
