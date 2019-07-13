#include "Node.h"

//Miembros
const string Node::getName()
{
	return name;
}

void Node::setName(string _name)
{
	name = _name;
}

const string Node::getLastName()
{
	return lastName;
}

void Node::setLastName(string _last_name)
{
	lastName = _last_name;
}

const string Node::getEmail()
{
	return email;
}

void Node::setEmail(string _email)
{
	email = _email;
}

void Node::setBirthDate(unsigned char _day, unsigned char _month, unsigned char _year)
{
	birthDay = (unsigned char)_day;
	birthMonth = (unsigned char)_month;
	birthYear = (unsigned char)_year;
}

const string Node::getFullName()
{
	return lastName + " " + name;
}

const unsigned int Node::getAge()
{
	unsigned int age = 19;
	if (birthYear <= age)
	{
		age = age - int((unsigned char)birthYear);
		return age;
	}
	else 
	{
		age = 0;
		return age;
	}
}



//SINGLE NODE
//Comparación
bool SingleNode::operator > (SingleNode & _right_s)
{
	return this->getAge() > _right_s.getAge();
}

bool SingleNode::operator < (SingleNode & _right_s)
{
	return this->getAge() < _right_s.getAge();
}

//Output
ostream & operator << (ostream & _out, SingleNode & _node)
{
	_out << "El nombre es : " << _node.getFullName() << "La edad es: " << _node.getAge() << "El correo es: " << _node.getEmail();
	
	if (_node.next != nullptr)
	{
		return _out << _node.next;
	}
	else
	{
		return _out;
	}
}

//Input
istream & operator >> (istream & _inp, SingleNode & _node)
{
	//Pedimos los datos
	cout << "Ingrese su nombre: \n";
	_inp >> _node.name;
	cout << "Ingrese su apellido:\n ";
	_inp >> _node.lastName;
	cout << "Ingrese su email: \n";
	_inp >> _node.email;
	cout << "Ingrese el dia que naciste: \n";
	_inp >> _node.birthDay;
	cout << "Ingrese el mes que naciste: \n";
	_inp >> _node.birthMonth;
	cout << "Ingrese el año en que naciste: \n";
	_inp >> _node.birthYear;

	return _inp;
}


//DOUBLE NODE

//Output
ostream & operator << (ostream & _out, DoubleNode & _d_noude)
{
	_out << "El nombre es : " << _d_noude.getFullName() << "La edad es: " << _d_noude.getAge() << "El correo es: " << _d_noude.getEmail();

	if (_d_noude.next != nullptr)
	{
		return _out << _d_noude.next;
	}
	else
	{
		return _out;
	}
}

//Input
istream & operator >> (istream & _inp, DoubleNode & _d_node)
{
	//Pedimos los datos
	cout << "Ingrese su nombre: \n";
	_inp >> _d_node.name;
	cout << "Ingrese su apellido:\n ";
	_inp >> _d_node.lastName;
	cout << "Ingrese su email: \n";
	_inp >> _d_node.email;
	cout << "Ingrese el dia que naciste: \n";
	_inp >> _d_node.birthDay;
	cout << "Ingrese el mes que naciste: \n";
	_inp >> _d_node.birthMonth;
	cout << "Ingrese el año en que naciste: \n";
	_inp >> _d_node.birthYear;

	return _inp;
}

//Comparadores
bool DoubleNode::operator > (DoubleNode & _right_s)
{
	return this->getAge() > _right_s.getAge();
}

bool DoubleNode::operator < (DoubleNode & _right_s)
{
	return this->getAge() < _right_s.getAge();
}




//Destructor
SingleNode::~SingleNode()
{
	if (next != nullptr)
	{
		delete next;
	}
}
//Destructor
DoubleNode::~DoubleNode()
{
	if (next != nullptr)
	{
		delete next;
	}
}
