#include "Arbol_Bin.h"
#include "Persona.h"

//Constructor para inicializar el primer nodo del árbol
template<class T>
Arbol_Bin<T>::Arbol_Bin()
{
	Raiz = nullptr;
}

//Destructor
template<class T>
Arbol_Bin<T>::~Arbol_Bin()
{
	//Se checa si la raiz es nula.
	if (Raiz != nullptr)
	{
		//De serlo, se elimina.
		delete Raiz;
	}
}

//Constructor para definir la raíz
template<class T>
Arbol_Bin<T>::Arbol_Bin(Nodos<T>* _nodo)
{
	Raiz = _nodo;
}

//Función para poder ingresar un nodo al árbol
template<class T>
int Arbol_Bin<T>::ingresar(Nodos<T>*& _nodo)
{
	//Primero checamos si la raíz es nula
	if (Raiz == nullptr)
	{
		//De ser así, ese nodo, será nuestra raíz
		Raiz = _nodo;
	}
	//Si no
	else
	{
		//Checamos si los datos del nodo son mayores que el de la raíz
		if (*_nodo > *Raiz)
		{
			//Si lo es, checamos si el puntero derecho de la raíz es nula
			if (Raiz->Derecha == nullptr)
			{
				//De ser así, ingresamos el nuevo nodo en ese puntero
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
		//Checamos si los datos del nodo ingresado son menores al de la raíz
		if (*_nodo < *Raiz)
		{
			//Si lo es, checamos si el puntero izquierdo está vacio
			if (Raiz->Izquierda == nullptr)
			{
				//De ser así, ingresamos el nodo en ese nivel 
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

//Función para eliminar un nodo específico
template<class T>
void Arbol_Bin<T>::eliminar(Nodos<T>* _nodo)
{
	//Checamos si la raíz está vacia
	if (Raiz == nullptr)
	{
		cout << "Abol vacio" << endl;
	}
	//Si no lo está
	else
	{
		//Creamos un puntero temporal que servirá como recipiente
		Nodos<T> * Temp;// = new Nodos<T>();

		//Checamos, si los datos ingresados son mayores a la raíz
		if (*_nodo > *Raiz)
		{
			//El recipiente almacenará el dato de la izquierda
			Temp = Raiz->Izquierda;
			//Finalmente avanzamos un nivel
			Raiz->Izquierda->eliminar(_nodo, Temp);
		}
		//Checamos, si los datos ingresados son menores a la raíz
		if (*_nodo < *Raiz)
		{
			//El recipiente almacenará el dato de la Derecha
			Temp = Raiz->Derecha;
			//Finalmente avanzamos un nivel
			Raiz->Derecha->eliminar(_nodo, Temp);
		}
	}
}

//Funciónes para imprimir
template<class T>
void Arbol_Bin<T>::in_orden()
{
	//Se checa si la raiz es nula
	if (Raiz != nullptr)
	{
		//De ser asi, se entra en la funcion.
		Raiz->in_orden();
	}
	else
	{
		//Caso contario, manda un mensaje indicando que el arbol esta vacio.
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_Bin<T>::pre_orden()
{
	//Se checa si la raiz es nula
	if (Raiz != nullptr)
	{
		//De ser asi, se entra en la funcion.
		Raiz->pre_orden();
	}
	else
	{
		//Caso contario, manda un mensaje indicando que el arbol esta vacio.
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_Bin<T>::post_orden()
{
	//Se checa si la raiz es nula
	if (Raiz != nullptr)
	{
		//De ser asi, se entra en la funcion.
		Raiz->post_orden();
	}
	else
	{
		//Caso contario, manda un mensaje indicando que el arbol esta vacio.
		cout << "Arbol_AVL vacio" << endl;
	}
}




//IMPORTANTE
template class Arbol_Bin<Persona>;
template class Arbol_Bin<int>;