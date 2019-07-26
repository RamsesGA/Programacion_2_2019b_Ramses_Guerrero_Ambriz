#include "Node.h"



Node::Node() {}
Node::~Node() {}

//Sobrecarga
ostream & operator<<(ostream & _out, Node * _tree)
{
	_out << "\nEl apellido es - - > " << _tree->last_name << "\nEl nombre es - - > " << _tree->name << "\nY la edad es - - > " << _tree->age << endl;
	return _out;
}
