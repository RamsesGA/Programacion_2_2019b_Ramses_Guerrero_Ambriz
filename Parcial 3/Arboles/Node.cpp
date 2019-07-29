#include "Node.h"

Node::Node() {}
Node::~Node() {}

//Sobrecargas
ostream & operator<<(ostream & _out, Node * _tree)
{
	_out << "\nEl apellido es - - > " << _tree->last_name << "\nEl nombre es - - > " << _tree->name << "\nY la edad es - - > " << _tree->age << endl;
	return _out;
}

//Comparador para el orden
bool operator<(string _last_or_name, Node * _tree)
{
	if (_last_or_name < _tree->last_name)
	{
		return _last_or_name < _tree->last_name;
	}
	else if (_last_or_name < _tree->name)
	{
		return _last_or_name < _tree->name;
	}
}
