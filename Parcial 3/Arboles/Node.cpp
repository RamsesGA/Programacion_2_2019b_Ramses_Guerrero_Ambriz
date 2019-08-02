#include "Node.h"

//Sobrecargas
ostream & operator<<(ostream & _out, Node * _tree)
{
	_out << "\nEl apellido es - - > " << _tree->last_name << "\nEl nombre es - - > " << _tree->name << "\nY la edad es - - > " << _tree->age << endl;
	return _out;
}

istream & operator>>(istream & _in, Node * _node)
{
	cout << "\nIngresa un apellido" << endl;
	_in >> _node->last_name;
	cout << "\nIngresa un nombre" << endl;
	_in >> _node->name;
	cout << "\nIngresa una edad" << endl;
	_in >> _node->age;
	return _in;
}

bool Node::operator<(Node & _node)
{
	if (last_name != _node.last_name)
	{
		return last_name < _node.last_name;
	}
	else if (name != _node.name)
	{
		return name < _node.name;
	}
	else if (age != _node.age)
	{
		return age < _node.age;
	}
	else if (last_name == _node.last_name && name == _node.name && age == _node.age)
	{
		return false;
	}
}

bool Node::operator>(Node & _node)
{
	if (last_name != _node.last_name)
	{
		return last_name > _node.last_name;
	}
	else if (name != _node.name)
	{
		return name > _node.name;
	}
	else if (age != _node.age)
	{
		return age > _node.age;
	}
	else if (last_name == _node.last_name && name == _node.name && age == _node.age)
	{
		return false;
	}
}


Node::Node() {}
Node::~Node() {}

