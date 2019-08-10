#include "Nodes.h"
#include "Persona.h"

//Función para ...
template<class T>
void Nodes<T>::PreordenLeft()
{
	if (Left != nullptr)
	{
		cout << Left->Dato << endl;
		Left->PreordenLeft();
		if (Left->Rigth != nullptr)
		{
			cout << Left->Rigth->Dato << endl;
			Left->Rigth->PreordenLeft();
		}
	}
}


//Función para ...
template<class T>
void Nodes<T>::PreordenRigth()
{
	if (Rigth != nullptr)
	{
		cout << Rigth->Dato << endl;
		Rigth->PreordenLeft();
		if (Rigth->Rigth != nullptr)
		{
			cout << Rigth->Rigth->Dato << endl;
			Rigth->Rigth->PreordenLeft();
		}
	}

}


//Función imprimir en I_O
template<class T>
void Nodes<T>::Inorden()
{
	if (Left != nullptr)
	{
		Left->Inorden();
	}
	cout << Dato << endl;
	if (Rigth != nullptr)
	{
		Rigth->Inorden();
	}
}


//Función imprimir en P_O
template<class T>
void Nodes<T>::Postorden()
{
	if (Left != nullptr)
	{
		Left->Postorden();
	}
	if (Rigth != nullptr)
	{
		Rigth->Postorden();
	}
	cout << Dato << endl;
}


//Función para poder checar si el árbol está balanceado
template<class T>
void Nodes<T>::Balance(int Cont)
{
	Nivel = Cont;
	if (Left != nullptr)
	{

		Cont++;
		Left->Balance(Cont);
		Cont--;
		balIzq = Left->pesoAct;
		pesoAct = ((Nivel * balDer) + (Nivel * balIzq));
	}

	if (Rigth != nullptr)
	{
		Cont++;
		Rigth->Balance(Cont);
		Cont--;
		balDer = Rigth->pesoAct;
		pesoAct = ((Nivel * balIzq) + (Nivel * balDer));

	}
	if (Left == nullptr && Rigth == nullptr)
	{
		pesoAct = Nivel;
	}

}


//Función para poder Rotar
template<class T>
void Nodes<T>::Rotacion()
{
	if (this->Left != nullptr)
	{
		this->Left->Rotacion();
	}
	if (this->Rigth != nullptr)
	{
		this->Rigth->Rotacion();
	}
	if (this->balDer < this->balIzq)
	{

		Nodes<T>*Temp = this->Left->Rigth;
		if (this->Ant->Dato > this->Dato)
		{
			this->Rigth->Ant = this->Ant;
			this->Ant->Rigth = this->Rigth;
			this->Ant = this->Rigth;
		}
		else if (this->Ant->Dato < this->Dato)
		{
			this->Left->Ant = this->Ant;
			this->Ant->Left = this->Left;
			this->Ant = this->Left;
		}

		this->Left->Rigth = this;
		this->Left = Temp;
		if (Temp != nullptr)
		{
			Temp->Ant = this;
		}

	}
	if (this->balIzq < this->balDer)
	{
		Nodes<T>*Temp = this->Rigth->Left;
		if (this->Ant->Dato > this->Dato)
		{
			this->Rigth->Ant = this->Ant;
			this->Ant->Rigth = this->Rigth;
			this->Ant = this->Rigth;
		}
		else if (this->Ant->Dato < this->Dato)
		{
			this->Left->Ant = this->Ant;
			this->Ant->Left = this->Left;
			this->Ant = this->Left;
		}

		this->Rigth->Left = this;
		this->Rigth = Temp;
		if (Temp != nullptr)
		{
			Temp->Ant = this;
		}
	}

}


//Función para poder ingresar un nodo al árbol
template<class T>
int Nodes<T>::Push(Nodes<T> * U, Nodes<T> * Ante)
{
	if (*U > *this)
	{
		if (Rigth == nullptr)
		{
			Rigth = U;
			Rigth->Ant = Ante;
		}
		else
		{
			Rigth->Push(U, Rigth);
		}
		return 0;
	}
	if (*U < *this)
	{
		if (Left == nullptr)
		{
			Left = U;
			Left->Ant = Ante;
		}
		else
		{
			Left->Push(U, Left);
		}
		return 0;
	}
	return 0;
}


//Función para eliminar un nodo especifico
template<class T>
int Nodes<T>::Pull(Nodes<T> * U, Nodes<T> * Temp)
{
	if (U == Temp)
	{
		if (Temp->Left == nullptr && Temp->Rigth == nullptr)
		{
			if (Temp->Ant->Dato < Temp->Dato)
			{
				Temp->Ant->Rigth = nullptr;
			}
			else if (Temp->Ant->Dato > Temp->Dato)
			{
				Temp->Ant->Left = nullptr;
			}
			Temp->Ant = nullptr;
			delete Temp;
			return 0;
		}
		else
		{
			if (Temp->Left != nullptr && Temp->Rigth == nullptr)
			{
				if (Temp->Ant->Dato < Temp->Dato)
				{
					Temp->Ant->Rigth = Temp->Left;
					Temp->Left->Ant = Temp->Ant;
				}
				else if (Temp->Ant->Dato > Temp->Dato)
				{
					Temp->Ant->Left = Temp->Left;
					Temp->Left->Ant = Temp->Ant;
				}
				Temp->Left = nullptr;
				delete Temp;
				return 0;
			}
			if (Temp->Left == nullptr && Temp->Rigth != nullptr)
			{
				if (Temp->Ant->Dato < Temp->Dato)
				{
					Temp->Ant->Rigth = Temp->Rigth;
					Temp->Rigth->Ant = Temp->Ant;
				}
				else if (Temp->Ant->Dato > Temp->Dato)
				{
					Temp->Ant->Left = Temp->Rigth;
					Temp->Rigth->Ant = Temp->Ant;
				}
				Temp->Rigth = nullptr;
				delete Temp;
				return 0;
			}

			if (Temp->Left != nullptr && Temp->Rigth != nullptr)
			{
				Nodes<T> * Te = new Nodes<T>();
				Te = &Temp->Rigth->Desplazar(Temp);
				return 0;
			}
		}
	}
	if (*U > *Temp)
	{
		Temp = Left;
		Left->Pull(U, Temp);
		return 0;
	}
	if (*U < *Temp)
	{
		Temp = Rigth;
		Rigth->Pull(U, Temp);
		return 0;
	}

	return 0;
}


//Sobrecarga del operador
template<class T>
bool Nodes<T>::operator < (Nodes & U)
{
	return U.Dato < Dato;

	/*if (U.apellido != apellido)
	{
		return U.apellido < apellido;
	}
	else if (U.nombre != nombre)
	{
		return U.nombre < nombre;
	}
	else if (U.edad != edad)
	{
		return U.edad < edad;
	}*/
}


//Sobrecarga del operador 
template<class T>
bool Nodes<T>::operator > (Nodes & U)
{
	return U.Dato > Dato;

	/*if (U.apellido != apellido)
	{
		return U.apellido > apellido;
	}
	else if (U.nombre != nombre)
	{
		return U.nombre > nombre;
	}
	else if (U.edad != edad)
	{
		return U.edad > edad;
	}*/
}


//Sobrecarga del operador
template<class T>
//revisar si el nodo que ingresamos es igual al nodo actual
bool Nodes<T>::operator == (Nodes & U)
{
	return Dato == U.Dato;
}


//Función para un intercambio de valores de nodos cuando sus punteros L and R tienen dos datos
template<class T>
Nodes<T> Nodes<T>::Desplazar(Nodes  * Temp)
{
	if (this->Left != nullptr)
	{
		Left->Desplazar(Temp);
	}
	else
	{
		Temp->Dato = this->Dato;
		this->Ant = nullptr;
		this->Rigth = nullptr;
		this->Left = nullptr;
		delete this;
		return *Temp;
	}
}


//Constructor para definir el valor de los punteros cuando el nodo se crea de manera automatica
template<class T>
Nodes<T>::Nodes(T D) : Dato(D)
{
	Left = nullptr;
	Rigth = nullptr;
}


//Constructor para definir el valor de los punteros del nuevo nodo
template<class T>
Nodes<T>::Nodes()
{
	Left = nullptr;
	Rigth = nullptr;
}


//Destructor
template<class T>
Nodes<T>::~Nodes()
{
	if (Left != nullptr)
	{
		delete Left;
	}
	if (Rigth != nullptr)
	{
		delete Rigth;
	}
}



//IMPORTANTE
template class Nodes<Persona>;
template class Nodes<int>;