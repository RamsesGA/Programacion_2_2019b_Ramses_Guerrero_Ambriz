#pragma once
#include "librerias.h"

using namespace std;
//Clase hija/madre
class carnivoros : public animales
{
	protected:
		carnivoros()
		{
			alimentacion = "carne";
		}
};