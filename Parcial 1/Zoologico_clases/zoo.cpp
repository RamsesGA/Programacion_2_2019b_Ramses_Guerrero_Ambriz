#include "librerias.h"

using namespace std;

//Clase abstracta padre
class zoologico
{
	public:
		int class_cantidadC;
		int class_cantidadH;
		int class_cantidadO;
		virtual void TipoDeComida() = 0;
};

//Clase hija
class carnivoro : public zoologico
{
	public:
		virtual void TipoDeComida() { cout << "Mucho cuidado, ellos comen carne" << endl; };
};
//Clase hija
class herbivoro : public zoologico
{
public:
	virtual void TipoDeComida() { cout << "Ellos pueden comer entre, frutas, hierbas, plantas u hojas" << endl; };
};
//Clase hija
class omnivoro : public zoologico
{
public:
	virtual void TipoDeComida() { cout << "Estos son especiales, su comida es entre plantas o carne de otros animales" << endl; };
};


int main()
{
	//Varables para saber la cantidad nueva de este animal
	int cantidadC = 0; int cantidadH = 0; int cantidadO = 0;
	//Variable para clasificar el animal
	int seleccion = 0; 
	//Nuevo tipo de dato especifico
	carnivoro animalC; herbivoro animalH; omnivoro animalO;

	cout << "Cuantos carnivoros nuevos entran " << endl;
	cin >> cantidadC;
	animalC.class_cantidadC = cantidadC;
	animalC.TipoDeComida();
	cout << "Cuantos herbivoros nuevos entran " << endl;
	cin >> cantidadH;
	animalH.class_cantidadH = cantidadH;
	animalH.TipoDeComida();
	cout << "Cuantos omnivoros nuevos entran " << endl;
	cin >> cantidadO;
	animalO.class_cantidadO = cantidadO;
	animalO.TipoDeComida();

	cin.get();
	cin.ignore();
	return 0;
}