#include "Arbol_Bin.h"
#include "Persona.h"

//Constructor para inicializar el primer nodo del �rbol
template<class T>
Arbol_Bin<T>::Arbol_Bin()
{
	Raiz = nullptr;
}

//Destructor
template<class T>
Arbol_Bin<T>::~Arbol_Bin(){}

//Constructor...
template<class T>
Arbol_Bin<T>::Arbol_Bin(Nodos<T>* _nodo)
{
	Raiz = _nodo;
}

//Funci�n para poder ingresar un nodo al �rbol
template<class T>
int Arbol_Bin<T>::ingresar(Nodos<T>* _nodo)
{
	//Primero checamos si la ra�z es nula
	if (Raiz == nullptr)
	{
		//De ser as�, ese nodo, ser� nuestra ra�z
		Raiz = _nodo;
	}
	//Si no
	else
	{
		//Checamos si los datos del nodo son mayores que el de la ra�z
		if (*_nodo > *Raiz)
		{
			//Si lo es, checamos si el puntero derecho de la ra�z es nula
			if (Raiz->Derecha == nullptr)
			{
				//De ser as�, ingresamos el nuevo nodo en ese puntero
				Raiz->Derecha = _nodo;
				Raiz->Derecha->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos un nivel hacia la Derecha
				Raiz->ingresar(_nodo, Raiz);
			}
		}
		//Checamos si los datos del nodo ingresado son menores al de la ra�z
		if (*_nodo < *Raiz)
		{
			//Si lo es, checamos si el puntero izquierdo est� vacio
			if (Raiz->Izquierda == nullptr)
			{
				//De ser as�, ingresamos el nodo en ese nivel 
				Raiz->Izquierda = _nodo;
				Raiz->Izquierda->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos de nivel hacia la izquierda
				Raiz->ingresar(_nodo, Raiz);
			}
		}
	}
	return 0;
}

//Funci�n para eliminar un nodo espec�fico
template<class T>
void Arbol_Bin<T>::eliminar(Nodos<T>* _nodo)
{
	//Checamos si la ra�z est� vacia
	if (Raiz == nullptr)
	{
		cout << "Abol vacio" << endl;
	}
	//Si no lo est�
	else
	{
		//Creamos un puntero temporal que servir� como recipiente
		Nodos<T> * Temp = new Nodos<T>();

		//Checamos, si los datos ingresados son mayores a la ra�z
		if (*_nodo > *Raiz)
		{
			//El recipiente almacenar� el dato de la izquierda
			Temp = Raiz->Izquierda;
			//Finalmente avanzamos un nivel
			Raiz->Izquierda->eliminar(_nodo, Temp);
		}
		//Checamos, si los datos ingresados son menores a la ra�z
		if (*_nodo < *Raiz)
		{
			//El recipiente almacenar� el dato de la Derecha
			Temp = Raiz->Derecha;
			//Finalmente avanzamos un nivel
			Raiz->Derecha->eliminar(_nodo, Temp);
		}
	}
}

//Funci�nes para imprimir
template<class T>
void Arbol_Bin<T>::in_orden()
{
	if (Raiz != nullptr)
	{
		Raiz->in_orden();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_Bin<T>::pre_orden()
{
	if (Raiz != nullptr)
	{
		Raiz->pre_orden();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_Bin<T>::post_orden()
{
	if (Raiz != nullptr)
	{
		Raiz->post_orden();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}




//IMPORTANTE
template class Arbol_Bin<Persona>;
template class Arbol_Bin<int>;