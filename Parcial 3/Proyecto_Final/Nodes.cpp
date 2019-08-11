#include "Nodes.h"
#include "Persona.h"

//Función para ...
template<class T>
void Nodos<T>::pre_orden_izq()
{
	if (Izquierda != nullptr)
	{
		cout << Izquierda->Dato << endl;
		Izquierda->pre_orden_izq();
		if (Izquierda->Derecha != nullptr)
		{
			cout << Izquierda->Derecha->Dato << endl;
			Izquierda->Derecha->pre_orden_izq();
		}
	}
}


//Función para ...
template<class T>
void Nodos<T>::pre_orden_dere()
{
	if (Derecha != nullptr)
	{
		cout << Derecha->Dato << endl;
		Derecha->pre_orden_izq();
		if (Derecha->Derecha != nullptr)
		{
			cout << Derecha->Derecha->Dato << endl;
			Derecha->Derecha->pre_orden_izq();
		}
	}

}


//Función imprimir en I_O
template<class T>
void Nodos<T>::in_orden()
{
	if (Izquierda != nullptr)
	{
		Izquierda->in_orden();
	}
	cout << Dato << endl;
	if (Derecha != nullptr)
	{
		Derecha->in_orden();
	}
}


//Función imprimir en P_O
template<class T>
void Nodos<T>::post_orden()
{
	if (Izquierda != nullptr)
	{
		Izquierda->post_orden();
	}
	if (Derecha != nullptr)
	{
		Derecha->post_orden();
	}
	cout << Dato << endl;
}


//Función para poder checar si el árbol está balanceado
template<class T>
void Nodos<T>::balance(int Cont)
{
	Nivel = Cont;
	if (Izquierda != nullptr)
	{

		Cont++;
		Izquierda->balance(Cont);
		Cont--;
		balIzq = Izquierda->pesoAct;
		pesoAct = ((Nivel * balDer) + (Nivel * balIzq));
	}

	if (Derecha != nullptr)
	{
		Cont++;
		Derecha->balance(Cont);
		Cont--;
		balDer = Derecha->pesoAct;
		pesoAct = ((Nivel * balIzq) + (Nivel * balDer));

	}
	if (Izquierda == nullptr && Derecha == nullptr)
	{
		pesoAct = Nivel;
	}

}


//Función para poder Rotar
template<class T>
void Nodos<T>::rotacion()
{
	if (this->Izquierda != nullptr)
	{
		this->Izquierda->rotacion();
	}
	if (this->Derecha != nullptr)
	{
		this->Derecha->rotacion();
	}
	if (this->balDer < this->balIzq)
	{

		Nodos<T>*Temp = this->Izquierda->Derecha;
		if (this->Ant->Dato > this->Dato)
		{
			this->Derecha->Ant = this->Ant;
			this->Ant->Derecha = this->Derecha;
			this->Ant = this->Derecha;
		}
		else if (this->Ant->Dato < this->Dato)
		{
			this->Izquierda->Ant = this->Ant;
			this->Ant->Izquierda = this->Izquierda;
			this->Ant = this->Izquierda;
		}

		this->Izquierda->Derecha = this;
		this->Izquierda = Temp;
		if (Temp != nullptr)
		{
			Temp->Ant = this;
		}

	}
	if (this->balIzq < this->balDer)
	{
		Nodos<T>*Temp = this->Derecha->Izquierda;
		if (this->Ant->Dato > this->Dato)
		{
			this->Derecha->Ant = this->Ant;
			this->Ant->Derecha = this->Derecha;
			this->Ant = this->Derecha;
		}
		else if (this->Ant->Dato < this->Dato)
		{
			this->Izquierda->Ant = this->Ant;
			this->Ant->Izquierda = this->Izquierda;
			this->Ant = this->Izquierda;
		}

		this->Derecha->Izquierda = this;
		this->Derecha = Temp;
		if (Temp != nullptr)
		{
			Temp->Ant = this;
		}
	}

}


//Función para poder ingresar un nodo al árbol
template<class T>
int Nodos<T>::ingresar(Nodos<T> * U, Nodos<T> * Ante)
{
	if (*U > *this)
	{
		if (Derecha == nullptr)
		{
			Derecha = U;
			Derecha->Ant = Ante;
		}
		else
		{
			Derecha->ingresar(U, Derecha);
		}
		return 0;
	}
	if (*U < *this)
	{
		if (Izquierda == nullptr)
		{
			Izquierda = U;
			Izquierda->Ant = Ante;
		}
		else
		{
			Izquierda->ingresar(U, Izquierda);
		}
		return 0;
	}
	return 0;
}


//Función para eliminar un nodo especifico
template<class T>
int Nodos<T>::eliminar(Nodos<T> * U, Nodos<T> * Temp)
{
	if (U == Temp)
	{
		if (Temp->Izquierda == nullptr && Temp->Derecha == nullptr)
		{
			if (Temp->Ant->Dato < Temp->Dato)
			{
				Temp->Ant->Derecha = nullptr;
			}
			else if (Temp->Ant->Dato > Temp->Dato)
			{
				Temp->Ant->Izquierda = nullptr;
			}
			Temp->Ant = nullptr;
			delete Temp;
			return 0;
		}
		else
		{
			if (Temp->Izquierda != nullptr && Temp->Derecha == nullptr)
			{
				if (Temp->Ant->Dato < Temp->Dato)
				{
					Temp->Ant->Derecha = Temp->Izquierda;
					Temp->Izquierda->Ant = Temp->Ant;
				}
				else if (Temp->Ant->Dato > Temp->Dato)
				{
					Temp->Ant->Izquierda = Temp->Izquierda;
					Temp->Izquierda->Ant = Temp->Ant;
				}
				Temp->Izquierda = nullptr;
				delete Temp;
				return 0;
			}
			if (Temp->Izquierda == nullptr && Temp->Derecha != nullptr)
			{
				if (Temp->Ant->Dato < Temp->Dato)
				{
					Temp->Ant->Derecha = Temp->Derecha;
					Temp->Derecha->Ant = Temp->Ant;
				}
				else if (Temp->Ant->Dato > Temp->Dato)
				{
					Temp->Ant->Izquierda = Temp->Derecha;
					Temp->Derecha->Ant = Temp->Ant;
				}
				Temp->Derecha = nullptr;
				delete Temp;
				return 0;
			}

			if (Temp->Izquierda != nullptr && Temp->Derecha != nullptr)
			{
				Nodos<T> * Te = new Nodos<T>();
				Te = &Temp->Derecha->desplazar(Temp);
				return 0;
			}
		}
	}
	if (*U > *Temp)
	{
		Temp = Izquierda;
		Izquierda->eliminar(U, Temp);
		return 0;
	}
	if (*U < *Temp)
	{
		Temp = Derecha;
		Derecha->eliminar(U, Temp);
		return 0;
	}

	return 0;
}


//Sobrecarga del operador
template<class T>
bool Nodos<T>::operator < (Nodos & U)
{
	return U.Dato < Dato;
}


//Sobrecarga del operador 
template<class T>
bool Nodos<T>::operator > (Nodos & U)
{
	return U.Dato > Dato;
}


//Sobrecarga del operador
template<class T>
//revisar si el nodo que ingresamos es igual al nodo actual
bool Nodos<T>::operator == (Nodos & U)
{
	return Dato == U.Dato;
}


//Función para un intercambio de valores de nodos cuando sus punteros L and R tienen dos datos
template<class T>
Nodos<T> Nodos<T>::desplazar(Nodos  * Temp)
{
	if (this->Izquierda != nullptr)
	{
		Izquierda->desplazar(Temp);
	}
	else
	{
		Temp->Dato = this->Dato;
		this->Ant = nullptr;
		this->Derecha = nullptr;
		this->Izquierda = nullptr;
		delete this;
		return *Temp;
	}
}


//Constructor para definir el valor de los punteros cuando el nodo se crea de manera automatica
template<class T>
Nodos<T>::Nodos(T D) : Dato(D)
{
	Izquierda = nullptr;
	Derecha = nullptr;
}


//Constructor para definir el valor de los punteros del nuevo nodo
template<class T>
Nodos<T>::Nodos()
{
	Izquierda = nullptr;
	Derecha = nullptr;
}


//Destructor
template<class T>
Nodos<T>::~Nodos()
{
	if (Izquierda != nullptr)
	{
		delete Izquierda;
	}
	if (Derecha != nullptr)
	{
		delete Derecha;
	}
}



//IMPORTANTE
template class Nodos<Persona>;
template class Nodos<int>;