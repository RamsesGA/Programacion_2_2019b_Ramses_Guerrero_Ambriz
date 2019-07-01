#include "Librerias_Clases.h"

//Funcion del metodo burbuja
vector <Nodo*> Bubble(vector <Nodo*> _punteros, int _contador)
{
	int temp = 0;
	bool bandera;
	//Ciclo para acomodar
	for (int i = _contador - 1; i > 0; i--)
	{
		bandera = false;
		for (int j = 0; j < _contador - 1; j++)
		{
			if (_punteros[j]->Dato > _punteros[j + 1]->Dato)
			{
				temp = _punteros[j]->Dato;
				_punteros[j]->Dato = _punteros[j + 1]->Dato;
				_punteros[j + 1]->Dato = temp;
				bandera = true;
			}
		}
		//Condición en caso de que el algortimos ya este ordenado
		if (bandera == false)
		{
			break;
		}
	}
	return _punteros;
}

//Funcion para poder añadir los nodos al vector
void Add_data_bubble(Nodo *_temp)
{
	vector <Nodo*> punteros;
	vector <Nodo*> resu_Final;
	int contador = 0;
	while (_temp->p_Next != nullptr)
	{
		contador++;
		punteros.push_back(_temp->p_Next);
		_temp = _temp->p_Next;
	}
	resu_Final = Bubble(punteros, contador);
	Print_bubble(resu_Final, contador);
}

//Función para poder imprimir el resultado final
void Print_bubble(vector <Nodo*> _resu_Final, int _contador)
{
	for (int i = 0; i < _contador; i++)
	{
		cout << " - -> ";
		cout << _resu_Final[i]->Dato;
	}
}