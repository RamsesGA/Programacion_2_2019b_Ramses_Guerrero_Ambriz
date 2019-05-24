#pragma once

class Vaca : public herbivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "La vaca pueden comer cualquier tipo de planta, la mas facil es el pasto"; };
	virtual void movimiento() { cout << "Son terrestres y usan cuatro patas para moverse"; };
	virtual void reproduccion() { cout << "Sexual y por etapas"; };
};

class Oruga : public herbivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "La oruga se alimenta de plantas tanto de dia como de noche"; };
	virtual void movimiento() { cout << "Son terrestres pero usan unas pequeñas patas para dezplasarse"; };
	virtual void reproduccion() { cout << "Estas no se reproducen, si no hasta ser mariposas"; };
};

class Cabra : public herbivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "Las cabras pueden comer cualquier tipo de planta"; };
	virtual void movimiento() { cout << "Son terrestres pero ellos usan sus cuatro patas para moverse"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Oveja : public herbivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "La oveja puede comer cualquier tipo de planta"; };
	virtual void movimiento() { cout << "Se desplazan con sus cuatro patas"; };
	virtual void reproduccion() { cout << "Sexual y por temporadas"; };
};

class Iguana : public herbivoro, public caracteristicasAnimal
{
	virtual void comer() { cout << "La iguana cuando es joven come insectos, cuando es adulta se vuelve herbivoro"; };
	virtual void movimiento() { cout << "Son terrestres y usan sus cuatro extremidades para moverse"; };
	virtual void reproduccion() { cout << "Sexual y estas ponen huevos en una fecha especifica"; };
};