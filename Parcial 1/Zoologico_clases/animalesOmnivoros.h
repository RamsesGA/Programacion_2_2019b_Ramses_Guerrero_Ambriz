#pragma once
//Clases hijas

class Avestruz : public omnivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "Esta ave puede consumir entre carne, ocacionalmente carroña y plantas"; };
	virtual void movimiento() { cout << "Son terrestres y usan dos patas para moverse"; };
	virtual void reproduccion() { cout << "Sexual y ponen huevos en un nido gigante"; };
};

class OsoPardo : public omnivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "Este oso consume vegetacion, frutas y animales"; };
	virtual void movimiento() { cout << "Son terrestres y usan cuatro patas para moverse, tambien pueden nadar"; };
	virtual void reproduccion() { cout << "Sexual y por etapas"; };
};

class Erizo : public omnivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "Se alimentan de insectos, frutas y vegetales"; };
	virtual void movimiento() { cout << "Son terrestres y usan cuatro patitas para moverse"; };
	virtual void reproduccion() { cout << "Sexual y por etapas"; };
};

class PezPayaso : public omnivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "Se alimentan de la anemona, moluscos, parasitos, entre otros"; };
	virtual void movimiento() { cout << "Son acuaticos y usan una aletita para nadar"; };
	virtual void reproduccion() { cout << "Sexual, la hembra pone huevos en un lugar calido y durante todo el año se reproducen"; };
};