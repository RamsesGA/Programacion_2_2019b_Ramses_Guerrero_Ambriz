#include "Librerias_Clases.h"

Lista_Linkeada_Clase::Lista_Linkeada_Clase()
{
	n_Header = new Nodo();
	n_Trailer = new Nodo();
	//Enlazo un nodo con el otro
	n_Header->p_Next = n_Trailer;
	n_Trailer->p_Prev = n_Header;
	//Declaro los punteros de los 2 a null
	n_Header->p_Prev = nullptr;
	n_Trailer->p_Next = nullptr;
}

int Lista_Linkeada_Clase::get_Front() const
{
	return n_Header->p_Next->Dato;
}

int Lista_Linkeada_Clase::get_Back() const
{
	return n_Trailer->p_Prev->Dato;
}

void Lista_Linkeada_Clase::add_Front(int _dato)
{
	Nodo *_nodo = new Nodo();
	_nodo->Dato = _dato;
	//Acomodamos el nuevo nodo
	_nodo->p_Prev = n_Header;
	_nodo->p_Next = n_Header->p_Next;

	//Cambiar los punteros
	n_Header->p_Next->p_Prev = _nodo;
	n_Header->p_Next = _nodo;
}

void Lista_Linkeada_Clase::add_Back(int _dato)
{
	Nodo *_nodo = new Nodo();
	_nodo->Dato = _dato;
	_nodo->p_Prev = n_Trailer->p_Prev;
	_nodo->p_Next = n_Trailer;

	//Cambiamos los punteros
	n_Trailer->p_Prev->p_Next = _nodo;
	n_Trailer->p_Prev = _nodo;

}

void Lista_Linkeada_Clase::remove_Front()
{
	Nodo *_nodo = n_Header->p_Next->p_Next;
	delete n_Header->p_Next;
	n_Header->p_Next = _nodo;
	_nodo->p_Prev = n_Header;
}

void Lista_Linkeada_Clase::remove_Back()
{
	Nodo *_nodo = n_Trailer->p_Prev->p_Prev;
	delete n_Trailer->p_Prev;
	n_Trailer->p_Prev = _nodo;
	_nodo->p_Next = n_Trailer;
}

void Lista_Linkeada_Clase::print_Reverse()
{
	Nodo *_nodo = n_Trailer->p_Prev;

	while (_nodo != n_Header)
	{
		cout << _nodo->Dato << " ";
		_nodo = _nodo->p_Prev;
	}
}

void Lista_Linkeada_Clase::print_Forward()
{
	Nodo *_nodo = n_Header->p_Next;

	while (_nodo != n_Trailer)
	{
		cout << _nodo->Dato << " ";
		_nodo = _nodo->p_Next;
	}
}

Lista_Linkeada_Clase::~Lista_Linkeada_Clase()
{
	while (n_Header->p_Next != n_Trailer)
	{
		remove_Front();
	}
	delete n_Header;
	delete n_Trailer;
}

