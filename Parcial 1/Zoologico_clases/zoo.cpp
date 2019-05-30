#include "librerias.h"

using namespace std;

//1- Funcion del metodo de ordenamiento quicksort
void quickS(vector <animales*> &NombresAnimales, int izquierda, int derecha) //Funcion de ordenamiento
{
	int i = izquierda; //Puntero inicial del lado menor
	int j = derecha; //Puntero inicial del lado mayor
	animales* temporal; //Variable para almacenar un dato necesario a intercambiar
	int pivote = (izquierda + derecha) / 2; //Pivote central
	//pivote++;
	while (i <= j)
	{
		while ((NombresAnimales[i]->_Nombre() < NombresAnimales[pivote]->_Nombre()) && (j <= derecha)) //En caso de que el número menor este en su lugar
		{
			i++;
		}
		while ((NombresAnimales[pivote]->_Nombre() < NombresAnimales[j]->_Nombre()) && (j > izquierda))  //En caso de que el número mayor este en su lugar
		{
			j--;
		}
		if (i <= j) //Si los número no estan en su lugar, se moveran de menor a mmayor
		{
			temporal = NombresAnimales[i];
			NombresAnimales[i] = NombresAnimales[j];
			NombresAnimales[j] = temporal;
			i++;
			j--;
		}
	}

	if (izquierda < j)
	{
		quickS(NombresAnimales, izquierda, j);
	}
	if (i < derecha)
	{
		quickS(NombresAnimales, i, derecha);
	}
}

//2- Funcion para imprimir la lista ordenada de forma ascendente
void imprimirarreglo(int tamaño, vector <animales*> &NombresAnimales) //Función solo para imprimir el resultado final
{
	for (int i = 0; i < tamaño; i++)
	{
		cout << NombresAnimales[i]->_Nombre() << " ";
	}
	cout << '\n' << "Terminado" << endl;
}

//3- Busqueda binaria
int busquedaBinaria(string dato, vector <animales*> &NombresAnimales)
{
	int inf = 0; int sup = 0; int mitad = 0; int datos = 0;
	char bandera = false;


	inf = 0;
	sup = NombresAnimales.size() - 1;

	while (inf <= sup)
	{
		mitad = (inf + sup) / 2;

		if (NombresAnimales[mitad]->_Nombre() == dato)
		{
			bandera = true;
			break;
		}
		if (NombresAnimales[mitad]->_Nombre() > dato)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (NombresAnimales[mitad]->_Nombre() < dato)
		{
			inf = mitad + 1;
			mitad = (inf + sup) / 2;
		}
	}
	if (bandera == true)
	{
		return mitad;
	}
}

//0- Funcion principal del código
int main()
{
	//Variables Omnivoros
	Avestruz animal1("Manuel");
	OsoPardo animal2("Po");
	Erizo animal3("Sonic");
	PezPayaso animal4("Nemo");
	//Varibales Carnivoros
	Leon animal5("Mufasa");
	Cocodrilo animal6("Anaki");
	OsoPolar animal7("Zhifu");
	Delfin animal8("Kikiri");
	Tiburon animal9("Emudi");
	Pulpo animal10("Monica");
	//Variables Herbivoros
	Vaca animal11("Bonifacio");
	Oruga animal12("Punto");
	Cabra animal13("Chupador");
	Oveja animal14("Mikasa");
	Iguana animal15("Orumaito");
	//Vector que almacena todos los nombres de los Omnivoros
	vector <animales*> NombresAnimalesO;
	//Todos los omnivoros
	NombresAnimalesO.push_back(&animal1);
	NombresAnimalesO.push_back(&animal2);
	NombresAnimalesO.push_back(&animal3);
	NombresAnimalesO.push_back(&animal4);
	//Todos los carnivoros
	NombresAnimalesO.push_back(&animal5);
	NombresAnimalesO.push_back(&animal6);
	NombresAnimalesO.push_back(&animal7);
	NombresAnimalesO.push_back(&animal8);
	NombresAnimalesO.push_back(&animal9);
	NombresAnimalesO.push_back(&animal10);
	//Todos los herbivoros
	NombresAnimalesO.push_back(&animal11);
	NombresAnimalesO.push_back(&animal12);
	NombresAnimalesO.push_back(&animal13);
	NombresAnimalesO.push_back(&animal14);
	NombresAnimalesO.push_back(&animal15);

	//1- Se manda a llamar y se envía los datos desordenados al quicksort
	quickS(NombresAnimalesO, 0, NombresAnimalesO.size() - 1); 
	//2- Funcion para mandar a llamar y que imprima los datos ordenados para verificar si es correcto
	imprimirarreglo(NombresAnimalesO.size(), NombresAnimalesO); 
	//3- Funcion para mandar a llamar el metodo de busqueda binario y ver si se encuentra tal letra principal

	//Variables para la busqueda binaria
	string posibleDato;
	int recibir;
	vector <animales> allNames;

	//Buscar el nombre del animal
	cout << "Ingresa el nombre posible de un animal" << endl;
	cin >> posibleDato;
	//Uuna variable de tipo entero va a tomar la posicion del dato en caso de que exista
	recibir = busquedaBinaria(posibleDato, NombresAnimalesO);
	//Al final se imprime
	cout << "Se encuentra en la posicion" << recibir << endl;

	cin.get();
	cin.ignore();
	return 0;
}