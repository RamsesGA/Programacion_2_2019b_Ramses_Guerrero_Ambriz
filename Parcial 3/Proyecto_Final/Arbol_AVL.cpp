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
Arbol_AVL<T>::Arbol_AVL(Nodes<T>* U)
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
int Arbol_AVL<T>::Push(Nodes<T> * U)
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
			if (Raiz->Rigth == nullptr)
			{
				//De ser as�, ingresamos el nuevo nodo en ese puntero
				Raiz->Rigth = U;
				Raiz->Rigth->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos un nivel hacia la derecha
				Raiz->Push(U, Raiz);
			}
		}
		//Checamos si los datos del nodo ingresado son menores al de la ra�z
		if (*U < *Raiz)
		{
			//Si lo es, checamos si el puntero izquierdo est� vacio
			if (Raiz->Left == nullptr)
			{
				//De ser as�, ingresamos el nodo en ese nivel 
				Raiz->Left = U;
				Raiz->Left->Ant = Raiz;
			}
			//Si no
			else
			{
				//Avanzamos de nivel hacia la izquierda
				Raiz->Push(U, Raiz);
			}
		}
	}
	return 0;
}

//Funci�nes para imprimir
template<class T>
void Arbol_AVL<T>::Inorden()
{
	if (Raiz != nullptr)
	{
		Raiz->Inorden();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_AVL<T>::Preorden()
{
	if (Raiz != nullptr)
	{
		/*cout << "Apellido: " << Raiz->apellido << endl;
		cout << "Nombre: " << Raiz->nombre << endl;
		cout << "Edad: " << Raiz->edad << endl;*/
		Raiz->PreordenLeft();
		Raiz->PreordenRigth();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}
template<class T>
void Arbol_AVL<T>::Postorden()
{
	if (Raiz != nullptr)
	{
		Raiz->Postorden();
	}
	else
	{
		cout << "Arbol_AVL vacio" << endl;
	}
}

//Funci�n para...
template<class T>
void Arbol_AVL<T>::Balance()
{
	if (Raiz->Left != nullptr)
	{
		Cont++;
		Raiz->Left->Balance(Cont);
		if (Raiz->Left->balDer != Raiz->Left->balIzq)
		{
			cout << "Lado izquierdo dezbalanceado" << endl;
		}
		Raiz->balIzq = Raiz->Left->balDer + Raiz->Left->balIzq;
	}
	if (Raiz->Rigth != nullptr)
	{
		Cont = 0;
		Cont++;
		Raiz->Rigth->Balance(Cont);
		if (Raiz->Rigth->balDer != Raiz->Rigth->balIzq)
		{
			cout << "Lado derecho no balanceado" << endl;
		}
		Raiz->balDer = Raiz->Rigth->balDer + Raiz->Rigth->balIzq;
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
void Arbol_AVL<T>::Pull(Nodes<T>* U)
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
		Nodes<T> * Temp = new Nodes<T>();

		//Checamos, si los datos ingresados son mayores a la ra�z
		if (*U > *Raiz)
		{
			//El recipiente almacenar� el dato de la izquierda
			Temp = Raiz->Left;
			//Finalmente avanzamos un nivel
			Raiz->Left->Pull(U, Temp);
		}
		//Checamos, si los datos ingresados son menores a la ra�z
		if (*U < *Raiz)
		{
			//El recipiente almacenar� el dato de la derecha
			Temp = Raiz->Rigth;
			//Finalmente avanzamos un nivel
			Raiz->Rigth->Pull(U, Temp);
		}
	}
}

//Funci�n de rotaci�n
template<class T>
void Arbol_AVL<T>::Rotacion()
{
	Balance();

	//se rota a la derecha
	if (Raiz->Left != nullptr)
	{
		Raiz->Left->Rotacion();
	}
	if (Raiz->Rigth != nullptr)
	{
		Raiz->Rigth->Rotacion();
	}
	if (Raiz->balDer < Raiz->balIzq)
	{
		//El nodo izquierdo se vulve la raiz
		Nodes<T>*Temp = Raiz->Left->Rigth;
		if (Temp != nullptr)
		{
			Temp->Ant = Raiz;
		}
		Raiz->Ant = Raiz->Left;
		Raiz->Left->Rigth = Raiz;
		Raiz->Left = Temp;
		Raiz = Raiz->Ant;
	}
	//se rota a la izquierda
	if (Raiz->balIzq < Raiz->balDer)
	{
		//El nodo derecho se vuelve la raiz
		Nodes<T>*Temp = Raiz->Rigth->Left;
		if (Temp != nullptr)
		{
			Temp->Ant = Raiz;
		}
		Raiz->Ant = Raiz->Rigth;
		Raiz->Rigth->Left = Raiz;
		Raiz->Rigth = Temp;
		Raiz = Raiz->Ant;
	}
}



//IMPORTANTE
template class Arbol_AVL<Persona>;
template class Arbol_AVL<int>;