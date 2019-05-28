#pragma once
#include "librerias.h"

using namespace std;
//Clases hijas

class Leon : public carnivoros
{
	public:
		Leon(){}
		Leon(string name)
		{
			nombre = name;
		}
		void comer() { cout << "El leon puede comer carne de vaca e incluso sus huesos"; };
		void movimiento() { cout << "Son terrestres pero ellos usan sus patas para moverse"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Cocodrilo : public carnivoros
{
	public:
		Cocodrilo(){}
		Cocodrilo(string name)
		{
			nombre = name;
		}
		void comer() { cout << "El tiburon come cualquier tipo de carne y tambien es capaz de cazarlo"; };
		void movimiento() { cout << "Terrestres y acuaticos"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class OsoPolar : public carnivoros
{
	public:
		OsoPolar() {}
		OsoPolar(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La camida preferida de los osos polares son las focas"; };
		void movimiento() { cout << "Terrestre, aunque tambien pueden nadar"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Delfin : public carnivoros
{
	public:
		Delfin() {}
		Delfin(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La alimentacion de los delfines puede variar entre, calamares, tortugas de mar, etc"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y estos no son monogamos, por lo tanto se pueden aparear con cualquiera"; };
};

class Tiburon : public carnivoros
{
	public:
		Tiburon() {}
		Tiburon(string name)
		{
			nombre = name;
		}
		void comer() { cout << "Los tiburones pueden preferir cierto tipo de comida, pero si es escaso se llegan a adaptar"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Pulpo : public carnivoros
{
	public:
		Pulpo() {}
		Pulpo(string name)
		{
			nombre = name;
		}
		void comer() { cout << "Los pulpos suelen comer el numero de veces conchas"; };
		void movimiento() { cout << "Acuatico"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};