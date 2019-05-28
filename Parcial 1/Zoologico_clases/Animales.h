#pragma once
#include "librerias.h"

using namespace std;

enum HEALTH
{
	good, bad, critical
};

//Clase padre
class animales
{
	protected:
		string alimentacion;
		char age;
		HEALTH health;
	public:
		string nombre;
		//Funciones básicas para vivir
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
};