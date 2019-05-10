#include "Librerias.h"

using namespace std;

void quickS(int tamaño)
{
	int uno = 0; int dos = 0; int contador = 0; int temp = 0; int menor = 0; int mayor = 0; int p = 0;
	int* arreglo = new int[tamaño];
	int* arregloMenor = new int[tamaño];
	int* arregloMayor = new int[tamaño];
	int i = 0; int j = tamaño - 1;
	int pivote = (tamaño / 2) - 1;
	
	//Ciclo para ingresar los datos
	cout << "Ingresa los datos" << endl;
	for (int i = 0; i < tamaño; i++)
	{
		cin >> arreglo[i]; cin.clear();
	}
	pivote = arreglo[pivote];
	//Ciclo de dos recorridos donde a la izquierda los menores y derecha mayore
	while (contador < (tamaño / 2) + 1)//Ciclo de dos recorridos donde a la izquierda los menores y derecha mayore
	{
		uno = arreglo[i];
		dos = arreglo[j];
		if ((uno < pivote == 0) && (dos > pivote == 0))//En el caso que se van a cambiar
		{
			temp = uno; uno = dos; dos = temp;
			arreglo[i] = uno; arreglo[j] = dos;
			i++; j--;
		}
		else if ((uno < pivote == 0) && (dos > pivote == 1))//En el caso donde el derecho es mayor
		{
			j--;
		}
		else if ((uno < pivote == 1) && (dos > pivote == 0))//En el caso donde el izquierdo si es menor
		{
			i++;
		}
		contador++;
	}
	for (int k = 0; k < tamaño; k++)
	{
		if (arreglo[k] < pivote)
		{
			arregloMenor[k] = arreglo[k];
			menor++;
		}
		else if (arreglo[k] > pivote)
		{
			arregloMayor[p] = arreglo[k];
			mayor++;
			p++;
		}
	}
	for (int a = 0; a < menor; a++)
	{
		for (int b = 0; b < menor - 1; b++)
		{
			if (arregloMenor[b] > arregloMenor[b + 1])
			{
				temp = arregloMenor[b];
				arregloMenor[b] = arregloMenor[b + 1];
				arregloMenor[b + 1] = temp;
			}
		}
	}
	for (int a = 0; a < mayor; a++)
	{
		for (int b = 0; b < mayor - 1; b++)
		{
			if (arregloMayor[b] > arregloMayor[b + 1])
			{
				temp = arregloMayor[b];
				arregloMayor[b] = arregloMayor[b + 1];
				arregloMayor[b + 1] = temp;
			}
		}
	}
	//Ciclo para imprimir
	for (int i = 0; i < menor; i++)
	{
		cout << arregloMenor[i] << " ";
	}
	for (int j = 0; j < mayor; j++)
	{
		cout << arregloMayor[j] << " ";
	}
}
int main()
{
	unsigned char valor;
	unsigned int tama = 0;
	cout << "Ingresa 1 para inciar" << endl;
	cin >> valor;
	if (valor == '1')
	{
		cout << "Ingresa una longitud" << endl; cin >> tama;
		quickS(tama);
	}
	else
	{
		exit(0);
	}
	cin.get();
	cin.ignore();
	return 0;
}