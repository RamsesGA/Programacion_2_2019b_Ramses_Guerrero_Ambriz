#pragma once
//Clase padre
class caracteristicasAnimal
{
	public:
		//Funciones básicas para vivir
		virtual void comer() = 0;
		virtual void movimiento() = 0;
		virtual void reproduccion() = 0;
};