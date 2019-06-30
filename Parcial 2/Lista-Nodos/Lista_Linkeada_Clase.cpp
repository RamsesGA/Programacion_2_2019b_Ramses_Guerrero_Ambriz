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
	Nodo *_temp = new Nodo();
	_temp->Dato = _dato;
	//Acomodamos el nuevo nodo
	_temp->p_Prev = n_Header;
	_temp->p_Next = n_Header->p_Next;

	//Cambiar los punteros
	n_Header->p_Next->p_Prev = _temp;
	n_Header->p_Next = _temp;
}

void Lista_Linkeada_Clase::add_Back(int _dato)
{
	Nodo *_temp = new Nodo();
	_temp->Dato = _dato;
	_temp->p_Prev = n_Trailer->p_Prev;
	_temp->p_Next = n_Trailer;

	//Cambiamos los punteros
	n_Trailer->p_Prev->p_Next = _temp;
	n_Trailer->p_Prev = _temp;
}

void Lista_Linkeada_Clase::remove_Front()
{
	if (n_Header->p_Next != n_Trailer)
	{
		//Guardamos el nodo a eliminar
		Nodo *_temp = n_Header->p_Next;
		//Cambiamos los punteros al nodo siguiente
		n_Header = n_Header->p_Next->p_Next;
		n_Header->p_Next->p_Prev = n_Header;

		//Desconectamos el nodo a eliminar
		_temp->p_Next = nullptr;
		_temp->p_Prev = nullptr;
		//Eliminamos el nodo
		delete _temp;
	}
	else
	{
		cout << "No se puede eliminar los elementos de una lista vacia UwU" << endl;
	}
}

void Lista_Linkeada_Clase::remove_Back()
{
	if (n_Trailer->p_Prev != n_Header)
	{
		//Guardamos el nodo a eliminar
		Nodo *_temp = n_Trailer->p_Prev;
		//Cambianmos los punteros al nodo siguiente
		n_Trailer->p_Prev = n_Trailer->p_Prev->p_Prev;
		n_Trailer->p_Prev->p_Next = n_Trailer;

		//Desconectamos el nodo a eliminar
		_temp->p_Next = nullptr;
		_temp->p_Prev = nullptr;
		//Eliminamos el nodo
		delete _temp;
	}
	else
	{
		cout << "No se puede eliminar los elementos de una lista vacia UwU" << endl;
	}
}

void Lista_Linkeada_Clase::print_Reverse()
{
	Nodo *_temp = n_Trailer->p_Prev;

	while (_temp != n_Header)
	{
		cout << _temp->Dato << " ";
		_temp = _temp->p_Prev;
	}
}

void Lista_Linkeada_Clase::print_Forward()
{
	Nodo *_temp = n_Header->p_Next;

	while (_temp != n_Trailer)
	{
		cout << _temp->Dato << " ";
		_temp = _temp->p_Next;
	}
}

void Lista_Linkeada_Clase::add_X(int _input, int _dato)
{
	//Guardamos el nodo siguiente
	Nodo *_temp = n_Header->p_Next;
	int _contador = 1;

	//Un ciclo para buscar el nodo
	while(_temp != n_Trailer)
	{
		if (_contador != _input)
		{
			_contador++;
			_temp = _temp->p_Next;
		}
		else
		{
			//Creamos el nuevo nodo y le adjuntamos el dato
			Nodo *_nodo_nuevo = new Nodo();
			_nodo_nuevo->Dato = _dato;

			//Ingresamos el nuevo nodo
			_nodo_nuevo->p_Next = _temp;
			_nodo_nuevo->p_Prev = _temp->p_Prev;

			//Desconectamos los nodos anteriores
			_temp->p_Prev = _nodo_nuevo;
			_nodo_nuevo->p_Prev->p_Next = _nodo_nuevo;
			break;
		}
	}
	if (_contador < _input)
	{
		cout << "No se encontro el nodo UvU" << endl;
	}
}

void Lista_Linkeada_Clase::remove_X(int _input)
{
	//Guardamos el nodo siguiente
	Nodo *_temp = n_Header->p_Next;
	int _contador = 1;

	//Un ciclo para buscar el nodo
	while (_temp != n_Trailer)
	{
		if (_contador != _input)
		{
			_contador++;
			_temp = _temp->p_Next;
		}
		else
		{
			_temp->p_Prev->p_Next = _temp->p_Next;
			_temp->p_Next->p_Prev = _temp->p_Prev;

			//Desconecto el nodo temporal
			_temp->p_Next = nullptr;
			_temp->p_Prev = nullptr;

			delete _temp;
			break;
		}
	}
	if (_contador < _input)
	{
		cout << "No se encontro el nodo UvU" << endl;
	}
}

Lista_Linkeada_Clase::~Lista_Linkeada_Clase()
{
	delete n_Header;
}

