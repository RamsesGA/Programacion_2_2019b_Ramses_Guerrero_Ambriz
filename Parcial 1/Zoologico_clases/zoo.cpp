#include "librerias.h"

using namespace std;

//1. Funcion del metodo de ordenamiento quicksort solo para nombres
void quickS_Nombres(vector <animales*> &AnimalesCompletosQS, int izquierda, int derecha) //Funcion de ordenamiento
{
	int i = izquierda; //Puntero inicial del lado menor
	int j = derecha; //Puntero inicial del lado mayor
	animales* temporal; //Variable para almacenar un dato necesario a intercambiar
	int pivote = (izquierda + derecha) / 2; //Pivote central

	while (i <= j)
	{
		//En caso de que el número menor este en su lugar
		while ((AnimalesCompletosQS[i]->_Nombre() < AnimalesCompletosQS[pivote]->_Nombre()) && (j <= derecha))
		{
			i++;
		}
		//En caso de que el número mayor este en su lugar
		while ((AnimalesCompletosQS[pivote]->_Nombre() < AnimalesCompletosQS[j]->_Nombre()) && (j > izquierda))
		{
			j--;
		}

		//Si los número no estan en su lugar, se moveran de menor a mayor
		if (i <= j)
		{
			temporal = AnimalesCompletosQS[i];
			AnimalesCompletosQS[i] = AnimalesCompletosQS[j];
			AnimalesCompletosQS[j] = temporal;
			i++;
			j--;
		}
	}

	if (izquierda < j)
	{
		quickS_Nombres(AnimalesCompletosQS, izquierda, j);
	}
	if (i < derecha)
	{
		quickS_Nombres(AnimalesCompletosQS, i, derecha);
	}
}
//1.Funcion para imprimir la lista ordenada de forma ascendente solo nombres
void imprimirarreglo_Nombre(int tamaño, vector <animales*> &AnimalesCompletosPRINT) //Función solo para imprimir el resultado final
{
	cout << "-----Ordenamiento por nombres-----" << endl;
	for (int i = 0; i < tamaño; i++)
	{ 
		cout << "Nombre: " << AnimalesCompletosPRINT[i]->_Nombre() << " Edad: " << AnimalesCompletosPRINT[i]->_Edad() << " Salud: " << AnimalesCompletosPRINT[i]->_Salud() << " ~ Posicion: " << i << endl;
	}
	cout << "\nTerminado" << endl;
}
//1.- Busqueda binaria del nombre
int busquedaBinaria(string dato, vector <animales*> &AnimalesCompletosBUSQUEDA)
{
	int inf = 0; int sup = 0; int mitad = 0; int datos = 0;


	inf = 0;
	sup = AnimalesCompletosBUSQUEDA.size() - 1;

	while (inf <= sup)
	{
		mitad = (inf + sup) / 2;

		if (AnimalesCompletosBUSQUEDA[mitad]->_Nombre() == dato)
		{
			return mitad;
			break;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Nombre() > dato)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Nombre() < dato)
		{
			inf = mitad + 1;
			mitad = (inf + sup) / 2;
		}
	}
}


//2.Funcion del metodo de ordenamiento quicksort solo para edades
void quickS_Edades(vector <animales*> &AnimalesCompletosQS, int izquierda, int derecha) //Funcion de ordenamiento
{
	int i = izquierda; //Puntero inicial del lado menor
	int j = derecha; //Puntero inicial del lado mayor
	animales* temporal; //Variable para almacenar un dato necesario a intercambiar
	int pivote = (izquierda + derecha) / 2; //Pivote central

	while (i <= j)
	{
		//En caso de que el número menor este en su lugar
		while ((AnimalesCompletosQS[i]->_Edad() < AnimalesCompletosQS[pivote]->_Edad()) && (j <= derecha))
		{
			i++;
		}
		//En caso de que el número mayor este en su lugar
		while ((AnimalesCompletosQS[pivote]->_Edad() < AnimalesCompletosQS[j]->_Edad()) && (j > izquierda))
		{
			j--;
		}

		//Si los número no estan en su lugar, se moveran de menor a mayor
		if (i <= j)
		{
			temporal = AnimalesCompletosQS[i];
			AnimalesCompletosQS[i] = AnimalesCompletosQS[j];
			AnimalesCompletosQS[j] = temporal;
			i++;
			j--;
		}
	}

	if (izquierda < j)
	{
		quickS_Edades(AnimalesCompletosQS, izquierda, j);
	}
	if (i < derecha)
	{
		quickS_Edades(AnimalesCompletosQS, i, derecha);
	}
}
//2.Funcion para imprimir la lista ordenada de forma ascendente
void imprimirarreglo_Edades(int tamaño, vector <animales*> &AnimalesCompletosPRINT) //Función solo para imprimir el resultado final
{
	cout << "\n-----Ordenamiento por edades-----" << endl;
	for (int i = 0; i < tamaño; i++)
	{
		cout << "Edad: " << AnimalesCompletosPRINT[i]->_Edad() << " Salud: " << AnimalesCompletosPRINT[i]->_Salud() << " Nombre: " << AnimalesCompletosPRINT[i]->_Nombre() << "  ~ Posicion: " << i << endl;
	}
	cout << "\nTerminado" << endl;
}
//2.- Busqueda binaria de la edad
int busquedaBinaria(unsigned char dato, vector <animales*> &AnimalesCompletosBUSQUEDA)
{
	int inf = 0; int sup = 0; int mitad = 0; int datos = 0;

	inf = 0;
	sup = AnimalesCompletosBUSQUEDA.size() - 1;

	while (inf <= sup)
	{
		mitad = (inf + sup) / 2;

		if (AnimalesCompletosBUSQUEDA[mitad]->_Edad() == dato)
		{
			return mitad;
			break;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Edad() > dato)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Edad() < dato)
		{
			inf = mitad + 1;
			mitad = (inf + sup) / 2;
		}
	}
}


//3.Funcion del metodo de ordenamiento quicksort solo para HEALTH
void quickS_Health(vector <animales*> &AnimalesCompletosQS, int izquierda, int derecha) //Funcion de ordenamiento
{
	int i = izquierda; //Puntero inicial del lado menor
	int j = derecha; //Puntero inicial del lado mayor
	animales* temporal; //Variable para almacenar un dato necesario a intercambiar
	int pivote = (izquierda + derecha) / 2; //Pivote central

	while (i <= j)
	{
		//En caso de que el número menor este en su lugar
		while ((AnimalesCompletosQS[i]->_Salud() < AnimalesCompletosQS[pivote]->_Salud()) && (j <= derecha))
		{
			i++;
		}
		//En caso de que el número mayor este en su lugar
		while ((AnimalesCompletosQS[pivote]->_Salud() < AnimalesCompletosQS[j]->_Salud()) && (j > izquierda))
		{
			j--;
		}

		//Si los número no estan en su lugar, se moveran de menor a mayor
		if (i <= j)
		{
			temporal = AnimalesCompletosQS[i];
			AnimalesCompletosQS[i] = AnimalesCompletosQS[j];
			AnimalesCompletosQS[j] = temporal;
			i++;
			j--;
		}
	}

	if (izquierda < j)
	{
		quickS_Health(AnimalesCompletosQS, izquierda, j);
	}
	if (i < derecha)
	{
		quickS_Health(AnimalesCompletosQS, i, derecha);
	}
}
//3.Funcion para imprimir la lista ordenada de forma ascendente
void imprimirarreglo_Health(int tamaño, vector <animales*> &AnimalesCompletosPRINT) //Función solo para imprimir el resultado final
{
	cout << "\n-----Ordenamiento por HEALTH-----" << endl;
	for (int i = 0; i < tamaño; i++)
	{
		cout << "Salud: " << AnimalesCompletosPRINT[i]->_Salud() << " Edad: " << AnimalesCompletosPRINT[i]->_Edad() << " Nombre: " << AnimalesCompletosPRINT[i]->_Nombre() << "  ~ Posicion: " << i << endl;
	}
	cout << "\nTerminado" << endl;
}
//3.- Busqueda binaria de HEALTH
int busquedaBinaria_Health(unsigned int dato, vector <animales*> &AnimalesCompletosBUSQUEDA)
{
	int inf = 0; int sup = 0; int mitad = 0; int datos = 0;

	inf = 0;
	sup = AnimalesCompletosBUSQUEDA.size() - 1;

	while (inf <= sup)
	{
		mitad = (inf + sup) / 2;

		if (AnimalesCompletosBUSQUEDA[mitad]->_Salud() == dato)
		{
			return mitad;
			break;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Salud() > dato)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (AnimalesCompletosBUSQUEDA[mitad]->_Salud() < dato)
		{
			inf = mitad + 1;
			mitad = (inf + sup) / 2;
		}
	}
}

//Funcion principal del código
int main()
{
	unsigned char seleccion = 0;
	//Variables para la busqueda binaria
	string posibleNombre;
	unsigned char posibleEdad;
	unsigned int posibleHealth;
	int recibir = 0;
	vector <animales> allNames;
	//Vector que almacena todos los datos de los Omnivoros
	vector <animales*> _animalesCompletos;

	//En general, todo esto es para enviar un nombre a cada animal y edad
	//Variables Omnivoros
	Avestruz animal1("manuel", '1', bad);
	OsoPardo animal2("po", '1', critical);
	Erizo animal3("sonic", '4', good);
	PezPayaso animal4("nemo", '2', bad);
	//Varibales Carnivoros
	Leon animal5("mufasa", '4', bad);
	Cocodrilo animal6("anaki", '3', good);
	OsoPolar animal7("zhifu", '6', bad);
	Delfin animal8("kikiri", '7', good);
	Tiburon animal9("emudi", '9', critical);
	Pulpo animal10("monica", '9', critical);
	//Variables Herbivoros
	Vaca animal11("bonifacio", '8', good);
	Oruga animal12("punto", '9', critical);
	Cabra animal13("chupador", '6', bad);
	Oveja animal14("mikasa", '8', critical);
	Iguana animal15("orumaito", '3', good);
	//--------------------------

	//Todos los omnivoros por nombre
	_animalesCompletos.push_back(&animal1);
	_animalesCompletos.push_back(&animal2);
	_animalesCompletos.push_back(&animal3);
	_animalesCompletos.push_back(&animal4);

	//Todos los carnivoros por nombre
	_animalesCompletos.push_back(&animal5);
	_animalesCompletos.push_back(&animal6);
	_animalesCompletos.push_back(&animal7);
	_animalesCompletos.push_back(&animal8);
	_animalesCompletos.push_back(&animal9);
	_animalesCompletos.push_back(&animal10);

	//Todos los herbivoros por nombre
	_animalesCompletos.push_back(&animal11);
	_animalesCompletos.push_back(&animal12);
	_animalesCompletos.push_back(&animal13);
	_animalesCompletos.push_back(&animal14);
	_animalesCompletos.push_back(&animal15);

	//Parte para la selección de ordenamiento
	cout << "Selecciona el metodo a ordenar\n 1-Nombre\n 2-Edad\n 3-Salud" << endl;
	cin >> seleccion;

	if (seleccion == '1')
	{	
		//Nombres------------------------------------------------------1
		//1- Se manda a llamar y se envía los datos desordenados al quicksort
		quickS_Nombres(_animalesCompletos, 0, _animalesCompletos.size() - 1);
		//Ordenamiento nombres
		//1- Funcion para mandar a llamar y que imprima los datos ordenados para verificar si es correcto
		imprimirarreglo_Nombre(_animalesCompletos.size(), _animalesCompletos);
		//1. Buscar el nombre del animal
		cout << "Ingresa el nombre posible de un animal" << endl;
		cin >> posibleNombre;
		//1.Una variable de tipo entero va a tomar la posicion del dato en caso de que exista
		recibir = busquedaBinaria(posibleNombre, _animalesCompletos);
		//1.Al final se imprime
		cout << "Se encuentra en la posicion: " << recibir << endl;
	}
	if (seleccion == '2')
	{
		//EDADES---------------------------------------2.
		quickS_Edades(_animalesCompletos, 0, _animalesCompletos.size() - 1);
		//Ordenamiento edad
		//2.
		imprimirarreglo_Edades(_animalesCompletos.size(), _animalesCompletos);
		//2. Buscar la edad del animal
		cout << "Ingresa la edad posible de un animal" << endl;
		cin >> posibleEdad;
		//2.Una variable de tipo entero va a tomar la posicion del dato en caso de que exista
		recibir = busquedaBinaria(posibleEdad, _animalesCompletos);
		//2.Al final se imprime
		cout << "Se encuentra en la posicion: " << recibir << endl;
	}
	if (seleccion == '3')
	{
		//SALUD--------------------------------------3 .
		quickS_Health(_animalesCompletos, 0, _animalesCompletos.size() - 1);
		//Ordenamiento salud
		//3.
		imprimirarreglo_Health(_animalesCompletos.size(), _animalesCompletos);
		//3. Buscar la edad del animal
		cout << "Ingresa la salud de un animal" << endl;
		cin >> posibleHealth;
		//3.Una variable de tipo entero va a tomar la posicion del dato en caso de que exista
		recibir = busquedaBinaria_Health(posibleHealth, _animalesCompletos);
		//3.Al final se imprime
		cout << "Se encuentra en la posicion: " << recibir << endl;
	}

	cin.get();
	cin.ignore();
	return 0;
}