#include "Librerias_Clases.h"

//Funcion del metodo burbuja
void Bubble(Nodo * _Header, Nodo *_Trailer)
{
	//Nodos temporales para poder hacer la comparación
	Nodo *temp = _Header;
	Nodo *temp_2;
	int valor_temp = 0;
	//Ciclo para tener un control de la longitud de las listas
	while (temp->p_Next != _Trailer)
	{
		//Se desplaza el nodo al siguiente en caso de que el if entre
		temp_2 = temp->p_Next;
		//Ciclo para poder checar valor por valor
		while (temp_2 != _Trailer)
		{
			//Condición para poder comparar y cambiar en caso de ser afirmativo
			if (temp_2->Dato < temp->Dato)
			{
				valor_temp = temp->Dato;
				temp->Dato = temp_2->Dato;
				temp_2->Dato = valor_temp;
			}
			//En casó que no se cumpla la condición avanzara el dato
			temp_2 = temp_2->p_Next;
		}
		//Necesario para evitar un while infinito
		temp = temp->p_Next;
	}
}