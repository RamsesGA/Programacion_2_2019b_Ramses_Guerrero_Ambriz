#pragma once
#include "Libraries.h"

class Person
{
	public:

		//Miembros
		string last_name;
		string name;
		unsigned int age;

		//Metodos


		//-Sobrecargas de operadores

		//Output
		friend ostream & operator << (ostream & _out, Person *_node)
		{
			_out << "\nEl apellido es - - > " << _node->last_name << "\nEl nombre es - - > " << _node->name << "\nY la edad es - - > " << _node->age << endl;
			return _out;
		}

		//Input
		friend istream & operator >> (istream &_in, Person *_node)
		{
			cout << "\nIngresa un apellido" << endl;
			_in >> _node->last_name;
			cout << "\nIngresa un nombre" << endl;
			_in >> _node->name;
			cout << "\nIngresa una edad" << endl;
			_in >> _node->age;
			return _in;
		}

		//Sobrecarga de operador menor que
		bool operator < (Person &_node)
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

		//Sobrecarga de operador mayor que
		bool operator > (Person &_node)
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

		Person(string _last, string _name, unsigned int _age)
		{
			last_name = _last;
			name = _name;
			age = _age;
		}

		Person();

		~Person();
};

