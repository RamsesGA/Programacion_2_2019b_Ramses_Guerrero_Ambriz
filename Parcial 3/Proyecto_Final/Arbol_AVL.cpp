#include "Arbol_AVL.h"
#include "Persona.h"

//Constructor para inicializar el primer nodo del árbol
template<class T>
Arbol_AVL<T>::Arbol_AVL()
{
	Raiz = nullptr;
}

//Constructor...
template<class T>
Arbol_AVL<T>::Arbol_AVL(Nodos<T>* U)
{
	Raiz = U;
}

//Destructor
template<class T>
Arbol_AVL<T>::~Arbol_AVL()
{
	if (Raiz != nullptr)
	{
		delete Raiz;
	}
}

//Función para poder ingresar un nodo al árbol
template<class T>
int Arbol_AVL<T>::ingresar(Nodos<T> * U)
{
	//Primero checamos si la raíz es nula
	if (Raiz == nullptr)
	{
		//De ser así, ese nodo, será nuestra raíz
		Raiz = U;
	}
	//Si no
	else
	{
		//Checamos si los datos del nodo son mayores que el de la raíz
		if (*U > *Raiz)
		{
			//Si lo es, checamos si el puntero derecho de la raíz es nula
			if (Raiz->Derecha == nullptr)
			{
				//De ser así, ingresamos el nuevo nodo en ese puntero
				Raiz->Derecha = U;
				Raiz->Derecha->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos un nivel hacia la Derecha
				Raiz->ingresar(U, Raiz);
			}
		}
		//Checamos si los datos del nodo ingresado son menores al de la raíz
		if (*U < *Raiz)
		{
			//Si lo es, checamos si el puntero izquierdo está vacio
			if (Raiz->Izquierda == nullptr)
			{
				//De ser así, ingresamos el nodo en ese nivel 
				Raiz->Izquierda = U;
				Raiz->Izquierda->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos de nivel hacia la izquierda
				Raiz->ingresar(U, Raiz);
			}
		}
	}
	return 0;
}

//Funciónes para imprimir
template<class T>
void Arbol_AVL<T>::in_orden()
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
void Arbol_AVL<T>::pre_orden()
{
	if (Raiz != nullptr)
	{
		/*cout << "Apellido: " << Raiz->apellido << endl;
		cout << "Nombre: " << Raiz->nombre << endl;
		cout << "Edad: " << Raiz->edad << endl;*/
		Raiz->pre_orden_izq();
		Raiz->pre_orden_dere();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_AVL<T>::post_orden()
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

//Función para...
template<class T>
void Arbol_AVL<T>::balance()
{
	if (Raiz->Izquierda != nullptr)
	{
		Cont++;
		Raiz->Izquierda->balance(Cont);
		if (Raiz->Izquierda->balDer != Raiz->Izquierda->balIzq)
		{
			cout << "Lado izquierdo desbalanceado" << endl;
		}
		Raiz->balIzq = Raiz->Izquierda->balDer + Raiz->Izquierda->balIzq;
	}
	if (Raiz->Derecha != nullptr)
	{
		Cont = 0;
		Cont++;
		Raiz->Derecha->balance(Cont);
		if (Raiz->Derecha->balDer != Raiz->Derecha->balIzq)
		{
			cout << "Lado derecho no balanceado" << endl;
		}
		Raiz->balDer = Raiz->Derecha->balDer + Raiz->Derecha->balIzq;
	}
	if (Raiz->balDer == Raiz->balIzq)
	{
		cout << "Arbol_AVL balanceado" << endl;
	}
	else
	{
		cout << "Arbol_AVL no balanceado" << endl;
	}
}

//Función para eliminar un nodo específico
template<class T>
void Arbol_AVL<T>::eliminar(Nodos<T>* U)
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
		Nodos<T> * Temp = new Nodos<T>();

		//Checamos, si los datos ingresados son mayores a la raíz
		if (*U > *Raiz)
		{
			//El recipiente almacenará el dato de la izquierda
			Temp = Raiz->Izquierda;
			//Finalmente avanzamos un nivel
			Raiz->Izquierda->eliminar(U, Temp);
		}
		//Checamos, si los datos ingresados son menores a la raíz
		if (*U < *Raiz)
		{
			//El recipiente almacenará el dato de la Derecha
			Temp = Raiz->Derecha;
			//Finalmente avanzamos un nivel
			Raiz->Derecha->eliminar(U, Temp);
		}
	}
}

//Función de rotación
template<class T>
void Arbol_AVL<T>::rotacion()
{
	balance();

	//se rota a la Derecha
	if (Raiz->Izquierda != nullptr)
	{
		Raiz->Izquierda->rotacion();
	}
	if (Raiz->Derecha != nullptr)
	{
		Raiz->Derecha->rotacion();
	}
	if (Raiz->balDer < Raiz->balIzq)
	{
		//El nodo izquierdo se vulve la raiz
		Nodos<T>*Temp = Raiz->Izquierda->Derecha;
		if (Temp != nullptr)
		{
			Temp->Ant = Raiz;
		}
		Raiz->Ant = Raiz->Izquierda;
		Raiz->Izquierda->Derecha = Raiz;
		Raiz->Izquierda = Temp;
		Raiz = Raiz->Ant;
	}
	//se rota a la izquierda
	if (Raiz->balIzq < Raiz->balDer)
	{
		//El nodo derecho se vuelve la raiz
		Nodos<T>*Temp = Raiz->Derecha->Izquierda;
		if (Temp != nullptr)
		{
			Temp->Ant = Raiz;
		}
		Raiz->Ant = Raiz->Derecha;
		Raiz->Derecha->Izquierda = Raiz;
		Raiz->Derecha = Temp;
		Raiz = Raiz->Ant;
	}
}



//IMPORTANTE
template class Arbol_AVL<Persona>;
template class Arbol_AVL<int>;