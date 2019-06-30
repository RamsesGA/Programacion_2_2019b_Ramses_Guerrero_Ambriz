#include "Librerias_Clases.h"

Nodo::~Nodo()
{
	if (p_Next != nullptr)
	{
		delete p_Next;
	}
}
