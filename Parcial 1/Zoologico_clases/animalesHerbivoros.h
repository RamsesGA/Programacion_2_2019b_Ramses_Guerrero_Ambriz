#pragma once
#include "librerias.h"

using namespace std;

class Vaca : public herbivoro
{
	public:
		Vaca() {}
		Vaca(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La vaca pueden comer cualquier tipo de planta, la mas facil es el pasto"; };
		void movimiento() { cout << "Son terrestres y usan cuatro patas para moverse"; };
		void reproduccion() { cout << "Sexual y por etapas"; };
};

class Oruga : public herbivoro
{
	public:
		Oruga() {}
		Oruga(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La oruga se alimenta de plantas tanto de dia como de noche"; };
		void movimiento() { cout << "Son terrestres pero usan unas pequeñas patas para dezplasarse"; };
		void reproduccion() { cout << "Estas no se reproducen, si no hasta ser mariposas"; };
};

class Cabra : public herbivoro
{
	public:
		Cabra() {}
		Cabra(string name)
		{
			nombre = name;
		}
		void comer() { cout << "Las cabras pueden comer cualquier tipo de planta"; };
		void movimiento() { cout << "Son terrestres pero ellos usan sus cuatro patas para moverse"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Oveja : public herbivoro
{
	public:
		Oveja() {}
		Oveja(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La oveja puede comer cualquier tipo de planta"; };
		void movimiento() { cout << "Se desplazan con sus cuatro patas"; };
		void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Iguana : public herbivoro
{
	public:
		Iguana() {}
		Iguana(string name)
		{
			nombre = name;
		}
		void comer() { cout << "La iguana cuando es joven come insectos, cuando es adulta se vuelve herbivoro"; };
		void movimiento() { cout << "Son terrestres y usan sus cuatro extremidades para moverse"; };
		void reproduccion() { cout << "Sexual y estas ponen huevos en una fecha especifica"; };
};