#pragma once
//Clase hija/madre
class carnivoros : public caracteristicasAnimal
{
	public:
		virtual void comer() = 0;
		virtual void movimiento() = 0;
		virtual void reproduccion() = 0;
};