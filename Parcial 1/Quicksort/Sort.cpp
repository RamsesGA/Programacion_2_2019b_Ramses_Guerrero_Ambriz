#include "Librerias.h"

using namespace std;

//1
void datos(int longi, int arreglo2[]) //Funcion para poder llenar el arreglo de datos 
{
	//Ciclo para ingresar los datos
	cout << "Ingresa los numeros" << endl;
	for (int i = 0; i < longi; i++)
	{
		cout << i + 1 << "...";
		cin >> arreglo2[i];
	}
}

//2
void quickS(int arreglo[], int izquierda, int derecha) //Funcion de ordenamiento
{
	int i = izquierda; //Puntero inicial del lado menor
	int j = derecha; //Puntero inicial del lado mayor
	int temporal = 0; //Variable para almacenar un dato necesario a intercambiar
	int pivote = arreglo[(izquierda + derecha) / 2]; //Pivote central

	while (i <= j)
	{
		while ((arreglo[i] < pivote) && (j <= derecha)) //En caso de que el número menor este en su lugar
		{
			i++;
		}
		while ((pivote < arreglo[j]) && (j > izquierda))  //En caso de que el número mayor este en su lugar
		{
			j--;
		}
		if (i <= j) //Si los número no estan en su lugar, se moveran de menor a mmayor
		{
			temporal = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = temporal;
			i++;
			j--;
		}
	}

	if (izquierda < j)
	{
		quickS(arreglo, izquierda, j);
	}
	if (i < derecha)
	{
		quickS(arreglo, i, derecha);
	}
}

//3
void imprimirarreglo(int tamaño, int arreglo[]) //Función solo para imprimir el resultado final
{
	for (int i = 0; i < tamaño; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << '\n' <<"Terminado" << endl;
}

int main()
{
	int tamaño = 0;
	int arreglo[255];

	cout << "Bienvenido a Quicksort" << endl;
	cout << "Ingresa una longitud" << endl;
	cin >> tamaño;
	//Inicio del envío y recibo de datos
	datos(tamaño, arreglo); //1
	quickS(arreglo, 0, tamaño - 1); //2
	imprimirarreglo(tamaño, arreglo); //3

	cin.get();
	cin.ignore();
	return 0;
}
