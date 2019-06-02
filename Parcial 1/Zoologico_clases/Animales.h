#pragma once
#include "librerias.h"

using namespace std;

enum HEALTH
{
	good = 10, bad = 5, critical = 1
};

//Clase padre
class animales
{
	protected:
		char age;
		HEALTH health;
		string alimentacion;
		string nombre;
	public:
		//Funciones virtuales a heredar
		virtual void comer() = 0;
		virtual void movimiento() = 0;
		virtual void reproduccion() = 0;

		//Sobrecarga de operadores
		bool operator > (string &s)
		{
			return nombre > s;
		}
		bool operator < (animales &A)
		{
			return nombre < A.nombre;
		}
		bool operator == (string &s)
		{
			return nombre == s;
		}

		//Mandando el dato a la funcion main
		string _Nombre()
		{
			return nombre;
		}
		char _Edad()
		{
			return age;
		}
		HEALTH _Salud()
		{
			return health;
		}
};