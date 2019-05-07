#include "Librerias.h"

using namespace std;

int binario(int num)
{
	return num & 1 ? true : false;
}

int multi(int num)
{
	int recipiente = 0;
	recipiente = num <<= 1;
	num = num >>= 1;
	num = num <<= 3;
	num = num + recipiente;
	return num;
}

int main()
{
	unsigned char valor;
	unsigned int numero = 0;

	cout << "1-Par o impar o 2-Multiplicacion x10" << endl;
	cin >> valor;

	switch (valor)
	 {
		case '1':
			cout << "Ingresa un valor" << endl;
			cin >> numero;
			binario(numero);
			if (binario(numero) == 0)
			{
				cout << "Es par" << endl;
			}
			else
			{
				cout << "Es impar" << endl;
			}
			break;
		case '2':
			cout << "Ingresa un valor" << endl;
			cin >> numero;
			cout << multi(numero) << endl;
			break;
	default:
		cout << "Valor erroneo" << endl;
		break;
	}
	cin.get();
	cin.ignore();
	return 0;
}