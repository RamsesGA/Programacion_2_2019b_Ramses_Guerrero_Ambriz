#pragma once


class Arboles
{
	public:
		//Metodos para AVL y BIN
		virtual void insertar() = 0;
		virtual void eliminar() = 0;
		virtual void in_orden() = 0;
		virtual void post_orden() = 0;
		virtual void pre_orden() = 0;


		//Metodos para AVL
		virtual void rotacion() = 0;
		virtual void balance() = 0;


		//Constructor
		Arboles();
		//Destructor
		~Arboles();
};

