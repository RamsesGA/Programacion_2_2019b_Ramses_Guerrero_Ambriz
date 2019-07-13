#include "List.h"

//Metodo para ingresar nodos
void SingleList::push(SingleNode * _push)
{
	if (start != nullptr)
	{
		SingleNode *temp = *start;
		SingleNode *prev = nullptr;

		while (temp != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = _push;
	}
	else
	{
		start = &_push;
	}
	s++;
}

void SingleList::push(SingleNode * _push, unsigned int _position)
{
	if (_position <= s)
	{
		unsigned int cont = 0;

		if (start != nullptr)
		{
			SingleNode *temp = *start;
			SingleNode *prev = nullptr;

			while (cont < _position)
			{
				prev = temp;
				temp = temp->next;
				cont++;
			}
			if (cont == _position)
			{
				prev->next = _push;
				_push->next = temp;
			}
		}
		else
		{
			start = &_push;
		}
		s++;
	}
	else
	{
		cout << "Fuera de rango" << endl;
	}
}

//Metodos para sacar un dato
SingleNode *SingleList::pull()
{
	if (start != nullptr)
	{
		SingleNode * temp = *start;
		SingleNode * prev = nullptr;
		unsigned int cont = 0;

		while (cont < s - 1)
		{
			prev = temp;
			temp = temp->next;
			cont++;
		}
		prev->next = nullptr;
		return temp;
	}
	else
	{
		return nullptr;
	}
	s--;
}

SingleNode *SingleList::pull(unsigned int _position)
{
	if (_position <= s)
	{
		if (start != nullptr)
		{
			SingleNode * temp = *start;
			SingleNode * prev = nullptr;
			unsigned int cont = 0;

			while (cont < _position)
			{
				prev = temp;
				temp = temp->next;
				cont++;
			}
			if (cont == _position)
			{
				prev->next = temp->next;
				temp->next = nullptr;
				return temp;
			}
			s--;
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		cout << "Fuera de rango" << endl;
		return nullptr;
	}
}

//Remove 
void SingleList::remove()
{
	if (start != nullptr)
	{
		SingleNode * temp = *start;
		SingleNode * prev = nullptr;
		int cont = 0;

		while (cont < s - 1)
		{
			prev = temp;
			temp = temp->next;
			cont++;
		}
		prev->next = nullptr;
		delete temp;
	}
	else
	{
		cout << "No hay nodos por eliminar" << endl;
	}
	s--;
}

void SingleList::remove(unsigned int _position)
{
	if (_position <= s)
	{
		if (start != nullptr)
		{
			SingleNode * temp = *start;
			SingleNode * prev = nullptr;
			unsigned int cont = 0;

			while (cont < _position)
			{
				prev = temp;
				temp = temp->next;
				cont++;
			}
			if (cont == _position)
			{
				prev->next = temp->next;
				temp->next = nullptr;
				delete temp;
				s--;
			}
		}
	}
	else
	{
		cout << "Fuera de rango" << endl;
	}
}

//Funcion para limpiar
void SingleList::clear()
{
	if (start != nullptr)
	{
		delete start;
	}
}

unsigned int SingleList::size()
{
	return s;
}

//Sobrecarga de operadores
ostream & operator << (ostream & _out, SingleList & _list)
{
	return _out << **_list.start;
}

SingleList::~SingleList()
{
}



//DOUBLE LIST
//Push
void DoubleList::push(DoubleNode * _node)
{
	if (start != nullptr)
	{
		DoubleNode * temp = *start;

		while (temp->next != nullptr)
		{
			temp->prev = temp;
			temp->next = temp->next->next;
			temp = temp->next;
		}
		temp->next = _node;
		_node->prev = temp;
		_node->next = nullptr;
	}
	else
	{
		start = &_node;
	}
	s++;
}

//Push con posición
void DoubleList::push(DoubleNode * _node, unsigned int _position)
{
	if (_position < s)
	{
		if ((*start) != nullptr)
		{
			unsigned int cont = 0;
			DoubleNode * temp = *start;

			while (cont < _position)
			{
				temp->prev = temp;
				temp->next = temp->next->next;
				temp = temp->next;
			}
			if (cont == _position)
			{
				temp->next->prev = _node;
				_node->next = temp->next;
				temp->next = _node;
				_node->prev = temp;
			}
		}
		else
		{
			*start = _node;
		}
		s++;
	}
	else
	{
		cout << "Fuera de rango" << endl;
	}
}

//Pull
DoubleNode *DoubleList::pull()
{
	return nullptr;
}

//Pull con posición
DoubleNode *DoubleList::pull(unsigned int _pos_node)
{
	return nullptr;
}

//Remover
void DoubleList::remove()
{
	if ((*start) != nullptr)
	{
		DoubleNode *temp = *start;
		while (temp->next != nullptr)
		{
			temp->prev = temp;
			temp->next = temp->next->next;
			temp = temp->next;
		}
		temp->prev->next = nullptr;
		temp->prev = nullptr;
		delete temp;
		s--;
	}
	else
	{
		cout << "No hay valores que eliminar" << endl;
	}
}

//Remover con posición
void DoubleList::remove(unsigned int _pos_node)
{
	if (_pos_node < s)
	{
		if (*start != nullptr)
		{
			DoubleNode * temp = *start;
			unsigned int cont = 0;
			while (cont < _pos_node)
			{
				temp->prev = temp;
				temp = temp->next;
				temp->next = temp->next->next;
			}
			temp->prev->next = nullptr;
			temp->prev = nullptr;
			delete temp;
			s--;
		}
		else
		{
			cout << "No hay valores a eliminar" << endl;
		}
	}
	else
	{
		cout << "Fuera de rango" << endl;
	}
}

//Sobrecarga de operadores
ostream & operator << (ostream & _out, DoubleList & _list_d)
{
	return _out << **_list_d.start;
}

//Limpieza
void DoubleList::clear()
{
	if ((*start) != nullptr)
	{
		delete *start;
	}
}

//Tamaño
unsigned int DoubleList::size()
{
	return s;
}

DoubleList::~DoubleList()
{
}
