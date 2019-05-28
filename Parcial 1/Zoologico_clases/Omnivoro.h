#pragma once
#include "librerias.h"

using namespace std;
//Clase hija/madre
class omnivoro : public animales
{
	protected:
		omnivoro()
		{
			alimentacion = "carne y plantas";
		}
};