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
		while ((NombresAnimales[i]->nombre < NombresAnimales[pivote]->nombre) && (j <= derecha)) //En caso de que el número menor este en su lugar
		{
			i++;
		}
		while ((NombresAnimales[pivote]->nombre < NombresAnimales[j]->nombre) && (j > izquierda))  //En caso de que el número mayor este en su lugar
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
		cout << NombresAnimales[i]->nombre << " ";
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

		if (NombresAnimales[mitad]->nombre == dato)
		{
			bandera = true;
			break;
		}
		if (NombresAnimales[mitad]->nombre > dato)
		{
			sup = mitad - 1;
			mitad = (inf + sup) / 2;
		}
		if (NombresAnimales[mitad]->nombre < dato)
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
	Avestruz animal1("Manuel"); //1
	OsoPardo animal2("Po"); //3
	Erizo animal3("Sonic");//4
	PezPayaso animal4("Nemo"); //2
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

	cout << "Ingresa la inicial de un nombre" << endl;
	cin >> posibleDato;
	recibir = busquedaBinaria(posibleDato, NombresAnimalesO);
	cout << "Se encuentra en la posicion" << recibir << endl;
	cin.get();
	cin.ignore();
	return 0;
}