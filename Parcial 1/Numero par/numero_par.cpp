#include <iostream>
#include <string>

using namespace std;

int main()
{
	string dividendo;
	char resuFinal;

	cout << "Ingresa el dividendo" << endl;
	getline(cin, dividendo);
	resuFinal = dividendo[dividendo.size() - 1];

	if (resuFinal == '0' || resuFinal == '2' || resuFinal == '4' || resuFinal == '6' || resuFinal == '8')
	{
		cout << "El numero es par" << endl;
	}
	else
	{
		cout << "El numero es impar" << endl;
	}

	cin.get();
	cin.ignore();
	return 0;
}