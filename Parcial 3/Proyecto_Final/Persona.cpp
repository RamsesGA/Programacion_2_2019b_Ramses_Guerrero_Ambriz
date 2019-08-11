#include "Persona.h"

//Sobrecarga de operador
bool Persona::operator<(Persona & U)
{
	if (U.apellido != apellido)
	{
		return U.apellido < apellido;
	}
	else if (U.nombre != nombre)
	{
		return U.nombre < nombre;
	}
	else if (U.edad != edad)
	{
		return U.edad < edad;
	}
}
//Sobrecarga de operador
bool Persona::operator>(Persona & U)
{
	if (U.apellido != apellido)
	{
		return U.apellido > apellido;
	}
	else if (U.nombre != nombre)
	{
		return U.nombre > nombre;
	}
	else if (U.edad != edad)
	{
		return U.edad > edad;
	}
}
//Sobrecarga de operador
bool Persona::operator==(Persona & P)
{
	if (apellido == P.apellido && nombre == P.nombre && edad == P.edad)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Sobrecarga del operador out
std::ostream & operator<<(std::ostream & os, Persona & P)
{
	os << "\nApellido: \n" << P.apellido << " \nNombre: \n" << P.nombre << " \nEdad: \n" << P.edad << std::endl;
	return os;
}

//Funci�n para poder guardar los datos ingresados en la clase persona
Persona::Persona(string N, string A, int E)
{
	nombre = N;
	apellido = A;
	edad = E;
}

//Constructor para la creaci�n de un nuevo nodo
Persona::Persona()
{
	cout << "Ingresa un apellido: \n"; cin >> apellido;
	cout << "Ingresa un nombre: \n"; cin >> nombre;
	cout << "Ingresa una edad: \n"; cin >> edad;
}

//Destructor
Persona::~Persona() {}