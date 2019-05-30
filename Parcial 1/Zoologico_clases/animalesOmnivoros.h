#pragma once
#include "librerias.h"

using namespace std;

//Clases hijas
class Avestruz : public omnivoro
{
	public:
		//Constructor general
		Avestruz() {};
		//Constructor con definicion de nombre desde main
		Avestruz(string name)
		{
			nombre = name;
		}
		//Constructor de edad, los datos estan en zoo.cpp main
		Avestruz(char _age)
		{
			age = _age;
		}
		//Funciones heredadas desde animales.h
		void comer() { cout << "Esta ave puede consumir entre carne, ocacionalmente carroña y plantas"; };
		void movimiento() { cout << "Son terrestres y usan dos patas para moverse"; };
		void reproduccion() { cout << "Sexual y ponen huevos en un nido gigante"; };
};

class OsoPardo : public omnivoro
{
	public:
		//Constructor general
		OsoPardo(){}
		//Constructor con definicion de nombre desde main
		OsoPardo(string name)
		{
			nombre = name;
		}
		//Constructor de edad, los datos estan en zoo.cpp main
		OsoPardo(char _age)
		{
			age = _age;
		}
		//Funciones heredadas desde animales.h
		void comer() { cout << "Este oso consume vegetacion, frutas y animales"; };
		void movimiento() { cout << "Son terrestres y usan cuatro patas para moverse, tambien pueden nadar"; };
		void reproduccion() { cout << "Sexual y por etapas"; };
};

class Erizo : public omnivoro
{
	public:
		//Constructor general
		Erizo(){}
		//Constructor con definicion de nombre desde main
		Erizo(string name)
		{
			nombre = name;
		}
		//Constructor de edad, los datos estan en zoo.cpp main
		Erizo(char _age)
		{
			age = _age;
		}
		//Funciones heredadas desde animales.h
		void comer() { cout << "Se alimentan de insectos, frutas y vegetales"; };
		void movimiento() { cout << "Son terrestres y usan cuatro patitas para moverse"; };
		void reproduccion() { cout << "Sexual y por etapas"; };
};

class PezPayaso : public omnivoro
{
	public:
		//Constructor general
		PezPayaso(){}
		//Constructor con definicion de nombre desde main
		PezPayaso(string name)
		{
			nombre = name;
		}
		//Constructor de edad, los datos estan en zoo.cpp main
		PezPayaso(char _age)
		{
			age = _age;
		}
		//Funciones heredadas desde animales.h
		void comer() { cout << "Se alimentan de la anemona, moluscos, parasitos, entre otros"; };
		void movimiento() { cout << "Son acuaticos y usan una aletita para nadar"; };
		void reproduccion() { cout << "Sexual, la hembra pone huevos en un lugar calido y durante todo el año se reproducen"; };
};