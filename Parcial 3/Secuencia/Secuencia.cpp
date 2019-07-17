#include <iostream>

using namespace std;

int secuencia(float _a, float _b, float _c)
{
	float media = 0;
	float result = 0;
	//Sacamos la cantidad de numeros a repetir
	int division = (_b / _c) - (_a / _c);

	media = division / 2;
	media = media * _c;
	media = _a + media;

	result = media * (division + _a);

	cout << "Los numeros ingresados son " << "- - > " <<_a << "- - > " << _b << "- - > " << _c << endl;

	return result;
}

int main()
{
	unsigned int menu = 0;
	float a = 0;
	float b = 0;
	float c = 0;

	cout << "\nIngrese \n0-Salir \n1-Iniciar" << endl;
	cin >> menu;

	switch (menu)
	{
		case 0:
			exit(0);
		case 1:
			//Simplemente ingresas los numeros enteros
			cout << "Ingresa un numero para A" << endl;
			cin >> a;
			cout << "Ingresa un numero para B" << endl;
			cin >> b;
			cout << "Ingresa un numero para C" << endl;
			cin >> c;
			//Limpiamos la pantalla
			system("cls");

			//Una condición, en caso de que no quieran usar números
			if (!isdigit(a) && !isdigit(b) && !isdigit(c))
			{
				cout << "\nEl numero final es - - > " << secuencia(a, b, c) << endl;
				return main();
			}
			else
			{
				//Se regresa al menu
				cout << "Ingrese numeros enteros" << endl;
				return main();
			}
	default:
		cout << "Ingrese un dato valido" << endl;
		return main();
	}
	
	cin.get();
	cin.ignore();
	return 0;
}