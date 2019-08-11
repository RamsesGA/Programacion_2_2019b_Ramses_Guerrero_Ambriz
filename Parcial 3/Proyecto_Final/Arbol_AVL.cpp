#include "Arbol_AVL.h"
#include "Persona.h"

//Constructor para inicializar el primer nodo del �rbol
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

//Funci�n para poder ingresar un nodo al �rbol
template<class T>
int Arbol_AVL<T>::ingresar(Nodos<T> * U)
{
	//Primero checamos si la ra�z es nula
	if (Raiz == nullptr)
	{
		//De ser as�, ese nodo, ser� nuestra ra�z
		Raiz = U;
	}
	//Si no
	else
	{
		//Checamos si los datos del nodo son mayores que el de la ra�z
		if (*U > *Raiz)
		{
			//Si lo es, checamos si el puntero derecho de la ra�z es nula
			if (Raiz->Derecha == nullptr)
			{
				//De ser as�, ingresamos el nuevo nodo en ese puntero
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
		//Checamos si los datos del nodo ingresado son menores al de la ra�z
		if (*U < *Raiz)
		{
			//Si lo es, checamos si el puntero izquierdo est� vacio
			if (Raiz->Izquierda == nullptr)
			{
				//De ser as�, ingresamos el nodo en ese nivel 
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

//Funci�nes para imprimir
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

//Funci�n para...
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

//Funci�n para eliminar un nodo espec�fico
template<class T>
void Arbol_AVL<T>::eliminar(Nodos<T>* U)
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
		if (*U > *Raiz)
		{
			//El recipiente almacenar� el dato de la izquierda
			Temp = Raiz->Izquierda;
			//Finalmente avanzamos un nivel
			Raiz->Izquierda->eliminar(U, Temp);
		}
		//Checamos, si los datos ingresados son menores a la ra�z
		if (*U < *Raiz)
		{
			//El recipiente almacenar� el dato de la Derecha
			Temp = Raiz->Derecha;
			//Finalmente avanzamos un nivel
			Raiz->Derecha->eliminar(U, Temp);
		}
	}
}

//Funci�n de rotaci�n
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