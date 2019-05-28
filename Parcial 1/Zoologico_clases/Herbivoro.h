#pragma once
#include "librerias.h"

using namespace std;
//Clase hija/madre
class herbivoro : public animales
{
	protected:
		herbivoro()
		{
			alimentacion = "Solo plantas";
		}
};