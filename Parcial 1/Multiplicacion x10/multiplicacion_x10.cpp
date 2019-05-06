#include "Librerias.h"

using namespace std;

int main()
{
	char numero[255];

	cout << "Ingresa un numero y le daremos el valor x10" << endl;
	cin >> numero;
	strcat_s(numero, "0");

	cout << "El numero x10 es: " << numero << endl;

	cin.get();
	cin.ignore();
	return 0;
}