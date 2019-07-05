#include "Librerias_Clases.h"

//vector <Nodo*> quickS(vector <Nodo*> _punteros, int izquierda, int derecha)
//{
//	int i = izquierda; //Puntero inicial del lado menor
//	int j = derecha; //Puntero inicial del lado mayor
//	int temporal = 0; //Variable para almacenar un dato necesario a intercambiar
//	int pivote = _punteros.size - 1; //Pivote central
//	
//	while (i <= j)
//	{
//		while ((_punteros[i]->Dato < pivote) && (j <= derecha)) //En caso de que el número menor este en su lugar
//		{
//			i++;
//		}
//		while ((pivote < _punteros[j]->Dato) && (j > izquierda))  //En caso de que el número mayor este en su lugar
//		{
//			j--;
//		}
//		if (i <= j) //Si los número no estan en su lugar, se moveran de menor a mmayor
//		{
//			temporal = _punteros[i]->Dato;
//			_punteros[i]->Dato = _punteros[j]->Dato;
//			_punteros[j]->Dato = temporal;
//			i++;
//			j--;
//		}
//	}
//	
//	if (izquierda < j)
//	{
//		quickS(_punteros, izquierda, j);
//	}
//	if (i < derecha)
//	{
//		quickS(_punteros, i, derecha);
//	}
//	return _punteros;
//}
//
//void Add_data_quick(Nodo *_temp)
//{
//	vector <Nodo*> punteros;
//	vector <Nodo*> resu_Final;
//	int contador = 0;
//	while (_temp->p_Next != nullptr)
//	{
//		contador++;
//		punteros.push_back(_temp->p_Next);
//		_temp = _temp->p_Next;
//	}
//	resu_Final = quickS(punteros, 0, contador - 1);
//	Print_quick(resu_Final, contador);
//}
//
//void Print_quick(vector <Nodo*> _resu_Final, int _contador)
//{
//	for (int i = 0; i < _contador; i++)
//	{
//		cout << " - -> ";
//		cout << _resu_Final[i]->Dato;
//	}
//}