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


//Importante
template class Node <Person>;
