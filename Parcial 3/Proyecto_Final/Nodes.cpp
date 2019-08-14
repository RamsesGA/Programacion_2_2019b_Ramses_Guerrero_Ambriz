#include "Nodes.h"
#include "Persona.h"

//Función para 
//template<class T>
//void Nodos<T>::pre_orden_izq()
//{
//	if (Izquierda != nullptr)
//	{
//		cout << Izquierda->Dato << endl;
//		Izquierda->pre_orden_izq();
//		if (Izquierda->Derecha != nullptr)
//		{
//			cout << Izquierda->Derecha->Dato << endl;
//			Izquierda->Derecha->pre_orden_izq();
//		}
//	}
//}
//
//
////Función para ...
//template<class T>
//void Nodos<T>::pre_orden_dere()
//{
//	if (Derecha != nullptr)
//	{
//		cout << Derecha->Dato << endl;
//		Derecha->pre_orden_izq();
//		if (Derecha->Derecha != nullptr)
//		{
//			cout << Derecha->Derecha->Dato << endl;
//			Derecha->Derecha->pre_orden_izq();
//		}
//	}
//
//}

//Funciónes para imprimir
template<class T>
void Nodos<T>::in_orden()
{
	//Usamos recursividad para recorrer primero el lado izq
	if (Izquierda != nullptr)
	{
		Izquierda->in_orden();
	}

	//Imprimimos los datos
	cout << Dato << endl;

	//Finalmente pasamos al lado derecho
	if (Derecha != nullptr)
	{
		Derecha->in_orden();
	}
}
template<class T>
void Nodos<T>::post_orden()
{
	//Usamos recursividad para recorrer primero el lado izq
	if (Izquierda != nullptr)
	{
		Izquierda->post_orden();
	}

	//Pasamos al lado derecho
	if (Derecha != nullptr)
	{
		Derecha->post_orden();
	}

	//Imprimimos los datos
	cout << Dato << endl;
}
template<class T>
void Nodos<T>::pre_orden()
{
	//Imprimimos los datos
	cout << Dato << endl;

	//Usamos recursividad para recorrer primero el lado izq
	if (Izquierda != nullptr)
	{
		Izquierda->pre_orden();
	}

	//Finalmente pasamos al lado derecho
	if (Derecha != nullptr)
	{
		Derecha->pre_orden();
	}
}


//Función para poder checar si el árbol está balanceado
template<class T>
int Nodos<T>::balanceado(int Cont)
{
	//Definimos el valor de una hoja
	if (this->Izquierda == nullptr && this->Derecha == nullptr)
	{
		this->Nivel = 0;
		return Cont;
	}

	//Condiciones para poder dar un peso/nivel al nodo correspondiente
	if (this->Izquierda != nullptr)
	{
		Cont = this->Izquierda->balanceado(this->contador);
		Cont--;
		this->Nivel = Cont;
		return Cont;
	}
	if(this->Derecha != nullptr)
	{
		Cont = this->Derecha->balanceado(this->contador);
		Cont++;
		this->Nivel = Cont;
		return Cont;
	}
}


//Función para poder Rotar
template<class T>
void Nodos<T>::rotacion()
{
	balanceado(this->contador);
	//Si el puntero izquierdo del nodo actual no es nulo.
	if (this->Izquierda != nullptr)
	{
		//Se avanza un nivel hacia la izquierda.
		this->Izquierda->rotacion();
		this->balanceado(this->contador);
	}

	//Si el puntero derecho del nodo actual no es nulo.
	if (this->Derecha != nullptr)
	{
		//Se avanza un nivel hacia la derecha.
		this->Derecha->rotacion();
		this->balanceado(this->contador);
	}

	//Si el nivel del nodo actual es igual a -2 
	if (this->Nivel == -2)
	{
		//Se crea un nodo temporal para almacenar el nodo al que se va a apuntar.
		Nodos<T>*Temp = this->Izquierda->Derecha;
		
		//Datos para redireccionar nodos anteriores
		if (this->Ant->Dato > this->Dato)
		{
			this->Derecha->Ant = this->Ant;
			this->Ant->Derecha = this->Derecha;
			this->Ant = this->Derecha;
		}
		
		//Datos para redireccionar nodos anteriores
		else if (this->Ant->Dato < this->Dato)
		{
			this->Izquierda->Ant = this->Ant;
			this->Ant->Izquierda = this->Izquierda;
			this->Ant = this->Izquierda;
		}

		//Rotacion de nodo hacia la derecha
		this->Izquierda->Derecha = this;
		this->Izquierda = Temp;
		if (Temp != nullptr)
		{
			Temp->Ant = this;
		}

	}

	//Si el nivel del nodo actual es igual a 2 
	if (this->Nivel == 2)
	{
		//Se crea un nodo temporal para almacenar el nodo al que se va a apuntar.
		Nodos<T>*Temp = this->Derecha->Izquierda;

		//Datos para redireccionar nodos anteriores
		if (this->Ant->Dato > this->Dato)
		{
			this->Derecha->Ant = this->Ant;
			this->Ant->Derecha = this->Derecha;
			this->Ant = this->Derecha;
		}

		//Datos para redireccionar nodos anteriores
		else if (this->Ant->Dato < this->Dato)
		{
			this->Izquierda->Ant = this->Ant;
			this->Ant->Izquierda = this->Izquierda;
			this->Ant = this->Izquierda;
		}

		//Rotacion de nodo hacia la izquierda
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
int Nodos<T>::ingresar(Nodos<T> *U, Nodos<T> *Ante)
{
	//Checamos si los datos recibidos son mayores a los existentes
	if (*U > *this)
	{
		//Si es así, checamos si el puntero dere está vacio 
		if (Derecha == nullptr)
		{
			//Si es así, el puntero apunta al dato ingresado
			Derecha = U;

			//Y se le asigna un padre
			Derecha->Ant = Ante;
		}

		//Si no está vacio
		else
		{
			//Avanzamos un nivel a la derecha
			Derecha->ingresar(U, Derecha);
		}
		return 0;
	}

	//En cambio, checamos si el valor es menor al ya existente
	if (*U < *this)
	{
		//En ese caso, checamos si el puntero izq está vacio
		if (Izquierda == nullptr)
		{
			//Si es así, el puntero apuntara al nuevo dato
			Izquierda = U;

			//Se le asigna un puntero padre al nodo anterior
			Izquierda->Ant = Ante;
		}
		//Si no está vacio
		else
		{
			//Avanzamos un nivel hacia la izquierda
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
	//Checamos si el dato ingresado es igual al temp
	if (U == Temp)
	{
		//En este caso buscamos si el nodo temp es una hoja
		if (Temp->Izquierda == nullptr && Temp->Derecha == nullptr)
		{
			//Si es así, checamos si el dato almacenado antes de temp es menor al que el tiene
			if (Temp->Ant->Dato < Temp->Dato)
			{
				//En ese caso desconectamos el dato de la derecha
				Temp->Ant->Derecha = nullptr;
			}
			//Si no, checamos si el dato almacenado antes de temp es mayor al que el tiene
			else if (Temp->Ant->Dato > Temp->Dato)
			{
				//En ese caso, desconectamos el dato de la derecha
				Temp->Ant->Izquierda = nullptr;
			}
			//Finalmente desconectamos el padre
			Temp->Ant = nullptr;
			//Mandamos a llamar el destructor
			delete Temp;
			return 0;
		}
		//Si no
		else
		{
			//Buscamos si el nodo es impar, con dato izq
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

			//O en su caso si el nodo es impar, con dato a la derecha
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

			//Finalmente buscamos si el nodo es par, apuntando a dos datos
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

//funcion para utilizar el datos
template<class T>
T Nodos<T>::get()
{
	return Dato;
}


//Función para un intercambio de valores de nodos cuando sus punteros L and R tienen dos datos
template<class T>
Nodos<T> Nodos<T>::desplazar(Nodos  * Temp)
{
	//checamos si el nodo a la izquierda no esta vacio 
	if (this->Izquierda != nullptr)
	{
		//si es así nos movemos a ese nodo
		Izquierda->desplazar(Temp);
	}
	//si no 
	else
	{
		//intercamobiamos el dato
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
	//definimos punteros nulos
	Izquierda = nullptr;
	Derecha = nullptr;
}


//Constructor para definir el valor de los punteros del nuevo nodo
template<class T>
Nodos<T>::Nodos()
{
	//definimos punteros nulos
	Izquierda = nullptr;
	Derecha = nullptr;
}


//Destructor
template<class T>
Nodos<T>::~Nodos()
{
	//Se checa si izquierda es diferente de nulo
	if (Izquierda != nullptr)
	{
		//Si es asi, se elimina
		delete Izquierda;
	}
	//Se checa si Derecha es diferente de nulo
	if (Derecha != nullptr)
	{
		//Si es asi, se elimina
		delete Derecha;
	}
}



//IMPORTANTE
template class Nodos<Persona>;
template class Nodos<int>;