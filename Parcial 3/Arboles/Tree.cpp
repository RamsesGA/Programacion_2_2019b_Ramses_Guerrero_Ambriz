#include "Tree.h"


//--Inicializador
template <class T>
Tree<T>::Tree() {}


//--Destructor
template <class T>
Tree<T>::~Tree() {}


//--Inserción con datos definidos
template <class T>
void Tree<T>::insert(T _dato)
{
	Node<T> *new_node = new Node<T>(_dato);
	insert(new_node);
}

template<class T>
Tree<T>::Tree(Node<T>* _root)
{
	root = _root;
}


//--Inserción con datos del usuario
template <class T>
void Tree<T>::insert(Node<T> *& _node)
{
	//Se revisa en caso de que aún no exista un nodo inicial
	if (root == nullptr)
	{
		//Guardamos el primer nodo que se ingresó a la variable
		root = _node;
	}
	//En caso de que la raíz ya está ocupada
	else if (root != nullptr)
	{
		root->insert_node(_node);
	}
}


//Impresion
template<class T>
void Tree<T>::in_order_tree()
{
	//Checamos en caso de que no tenga raíz
	if (root != nullptr)
	{
		root->in_order();
	}
	else
	{
		cout << "No hay una raiz" << endl;
	}
}

template<class T>
void Tree<T>::pre_order_tree()
{
	//Checamos en caso de que no tenga raíz
	if (root != nullptr)
	{
		root->pre_order();
	}
	else
	{
		cout << "No hay una raiz" << endl;
	}
}

template<class T>
void Tree<T>::post_order_tree()
{
	//Checamos en caso de que no tenga raíz
	if (root != nullptr)
	{
		root->post_order();
	}
	else
	{
		cout << "No hay una raiz" << endl;
	}
}

template<class T>
void Tree<T>::check_tree()
{
	if (root != nullptr)
	{
		root->check();
	}
	else
	{
		cout << "No hay una raiz" << endl;
	}
}


template<class T>
void Tree<T>::eliminate_in_tree(Node<T> *_info)
{
	if (root != nullptr)
	{
		root->eliminate(_info);
	}
	else
	{
		cout << "No hay una raiz" << endl;
	}
}


template <class T>
void Tree<T>::rotate_right(Node<T> *&_node)
{
	//Creamos un temp para que nos sirva de almacen
	Node<T> *temp;

	if (_node->p_left != nullptr)
	{
		//En caso de que si tenga algo temp almacena el dato
		temp = _node->p_left;

		if (temp->p_rigth != nullptr)
		{
			_node->p_left = temp->p_rigth;
		}
		//En caso de que si este vacio
		temp->p_rigth = _node;

		if (_node != root)
		{
			//Creamos otro puntero para que almacene la raíz
			Node<T> *temp2 = root;

			//Creamos un ciclo para que nos ayude a buscar los datos del otro lado
			while (temp2 != nullptr)
			{
				if (temp2 > _node)
				{
					if (temp2->p_left == _node)
					{
						//Hacemos el cambio
						temp2->p_left = temp;
					}
					else
					{
						temp2 = temp2->p_left;
					}
				}
				else if (temp2 < _node)
				{
					if (temp2->p_rigth == _node)
					{
						//Hacemos el cambio
						temp2->p_rigth = temp;
					}
					else
					{
						temp2 = temp2->p_rigth;
					}
				}
			}
		}
	}
}
template <class T>
void Tree<T>::rotate_left(Node<T> *&_node)
{
	//Creamos un temp para que nos sirva de almacen
	Node<T> *temp;

	if (_node->p_rigth != nullptr)
	{
		//En caso de que si tenga algo temp almacena el dato
		temp = _node->p_rigth;

		if (temp->p_left != nullptr)
		{
			_node->p_rigth = temp->p_left;
		}
		//En caso de que si este vacio
		temp->p_left = _node;

		if (_node != root)
		{
			//Creamos otro puntero para que almacene la raíz
			Node<T> *temp2 = root;

			//Creamos un ciclo para que nos ayude a buscar los datos del otro lado
			while (temp2 != nullptr)
			{
				if (temp2 > _node)
				{
					if (temp2->p_rigth == _node)
					{
						//Hacemos el cambio
						temp2->p_rigth = temp;
					}
					else
					{
						temp2 = temp2->p_rigth;
					}
				}
				else if (temp2 < _node)
				{
					if (temp2->p_left == _node)
					{
						//Hacemos el cambio
						temp2->p_left = temp;
					}
					else
					{
						temp2 = temp2->p_left;
					}
				}
			}
		}
	}
}




//Importante
template class Tree <Person>;