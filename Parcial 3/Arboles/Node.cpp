#include "Node.h"

template<class T>
Node<T>::Node(T _info)
{
	Personas = _info;
}

template<class T>
inline Node<T>::Node(){}

template<class T>
inline Node<T>::~Node(){}

template<class T>
istream & operator>>(istream & _in, Node<T>& _node)
{
	_in >> _node.Personas;
	return _in;
}

//Importante
template class Node <Person>;

