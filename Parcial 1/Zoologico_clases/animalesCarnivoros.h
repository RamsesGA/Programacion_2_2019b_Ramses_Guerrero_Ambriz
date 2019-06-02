#pragma once
#include "librerias.h"

using namespace std;
//Clases hijas

class Leon : public carnivoros
{
	public:
		//Constructor general
		Leon(){}

		//Constructor
		Leon(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "El leon puede comer carne de vaca e incluso sus huesos"; };
		void movimiento() { cout << "Son terrestres pero ellos usan sus patas para moverse"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Cocodrilo : public carnivoros
{
	public:
		//Constructor general
		Cocodrilo(){}

		//Constructor
		Cocodrilo(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "El tiburon come cualquier tipo de carne y tambien es capaz de cazarlo"; };
		void movimiento() { cout << "Terrestres y acuaticos"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class OsoPolar : public carnivoros
{
	public:
		//Constructor general
		OsoPolar() {}

		//Constructor
		OsoPolar(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "La camida preferida de los osos polares son las focas"; };
		void movimiento() { cout << "Terrestre, aunque tambien pueden nadar"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Delfin : public carnivoros
{
	public:
		//Constructor general
		Delfin() {}

		//Constructor
		Delfin(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "La alimentacion de los delfines puede variar entre, calamares, tortugas de mar, etc"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y estos no son monogamos, por lo tanto se pueden aparear con cualquiera"; };
};

class Tiburon : public carnivoros
{
	public:
		//Constructor general
		Tiburon() {}

		//Constructor
		Tiburon(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "Los tiburones pueden preferir cierto tipo de comida, pero si es escaso se llegan a adaptar"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Pulpo : public carnivoros
{
	public:
		//Constructor general
		Pulpo() {}

		//Constructor
		Pulpo(string name, char _age, HEALTH _dato)
		{
			nombre = name;
			age = _age;
			health = _dato;
		}

		//Funciones heredadas desde animales.h
		void comer() { cout << "Los pulpos suelen comer el numero de veces conchas"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};