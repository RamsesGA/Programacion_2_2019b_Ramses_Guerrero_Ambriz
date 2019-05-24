#pragma once
//Clases hijas

class Leon : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "El leon puede comer carne de vaca e incluso sus huesos"; };
	virtual void movimiento() { cout << "Son terrestres pero ellos usan sus patas para moverse"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Cocodrilo : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "El tiburon come cualquier tipo de carne y tambien es capaz de cazarlo"; };
	virtual void movimiento() { cout << "Terrestres y acuaticos"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class OsoPolar : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "La camida preferida de los osos polares son las focas"; };
	virtual void movimiento() { cout << "Terrestre, aunque tambien pueden nadar"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Delfin : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "La alimentacion de los delfines puede variar entre, calamares, tortugas de mar, etc"; };
	virtual void movimiento() { cout << "Acuatico"; };
	virtual void reproduccion() { cout << "Sexual y estos no son monogamos, por lo tanto se pueden aparear con cualquiera"; };
};

class Tiburon : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "Los tiburones pueden preferir cierto tipo de comida, pero si es escaso se llegan a adaptar"; };
	virtual void movimiento() { cout << "Acuatico"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Pulpo : public carnivoros, public caracteristicasAnimal
{
	virtual void comer() { cout << "Los pulpos suelen comer el numero de veces conchas"; };
	virtual void movimiento() { cout << "Acuatico"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};